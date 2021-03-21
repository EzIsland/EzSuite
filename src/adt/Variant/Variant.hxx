export module ezs.adt.Variant;
import ezs.tfl;
import ezs.uint_t;
import ezs.cfl.assert;
import <string>;

namespace ezs::adt {
namespace {

///
/// @brief A VariantUnion is an untagged union of N >= 1 types numbered 0 to N-1
///
/// If N is 1, the union contains exactly one value and it is implemented as
/// a union with a single member of that type (see partial specialization).
/// Otherwise, the VariantUnion is implemented as a union between type 0
/// and a VariantUnion of the remaining N-1 types.
///
/// We say that the VariantUnion is inactive if none of its members are
/// active elements of the union. We say that it is active in type 0 if
/// mHead is the active element of the union. We say that it is active in type M
/// for M != 0 if mTail is the active element of the union and mTail
/// is active in type M-1.
///
/// Invariant: A given VariantUnion is in one of N+1 states, either it is
/// inactive, or it is active in element M for M in 0 to N-1.
template <tfl::Value Head, tfl::Value... Tail> union VariantUnion final {
private:
  ///
  /// @brief 
  ///
  Head mHead;

  ///
  /// @brief 
  ///
  VariantUnion<Tail...> mTail;

  ///
  /// @brief Returns true of if pIdx is a valid index into this VariantUnion.
  ///
  static constexpr bool isValidIdx(uint_t pIdx) noexcept;

public:
  ///
  /// @brief Constructs a VariantUnion in the active state with active element idx.
  /// The active element is forward-constructed from the arguments pArgs.
  ///
  template <uint_t idx, tfl::ForwardRef... Args>
  constexpr VariantUnion(tfl::ValueTag<idx>, Args &&...pArgs) noexcept
      requires(isValidIdx(idx));

  ///
  /// Destroys this VariantUnion. Requires that the VariantUnion be inactive.
  /// 
  constexpr ~VariantUnion() noexcept;

  constexpr VariantUnion() noexcept = delete;
  constexpr VariantUnion(const VariantUnion &) noexcept = delete;
  constexpr VariantUnion(VariantUnion &&) noexcept = delete;
  constexpr VariantUnion &operator=(const VariantUnion &) &noexcept = delete;
  constexpr VariantUnion &operator=(VariantUnion &&) &noexcept = delete;

  template <uint_t idx>
  [[nodiscard]] constexpr tfl::SelectType<idx, Head, Tail...> &get() &noexcept
      requires(isValidIdx(idx));
  
  template <uint_t idx>
  [[nodiscard]] constexpr const tfl::SelectType<idx, Head, Tail...> &
  get() const &noexcept
      requires(isValidIdx(idx));

  ///
  /// Requires the VariantUnion to be inactive.
  /// Makes the VariantUnion active in element idx, with
  /// a value constructed from the arguments Args.
  ///
  template <uint_t idx, tfl::ForwardRef... Args>
  constexpr void emplace(Args &&...pArgs) noexcept
      requires(isValidIdx(idx));

  ///
  /// Requires the variant union to be active in element pIdx;
  /// Makes the VariantUnion inactive by destroying the active element.
  ///
  constexpr void destroy(uint_t pIdx) noexcept;
};

template <tfl::Value Head, tfl::Value... Tail>
constexpr bool VariantUnion<Head, Tail...>::isValidIdx(uint_t idx) noexcept {
  return idx <= sizeof...(Tail);
}

template <tfl::Value Head, tfl::Value... Tail>
constexpr VariantUnion<Head, Tail...>::~VariantUnion() noexcept {}

template <tfl::Value Head, tfl::Value... Tail>
template <uint_t idx, tfl::ForwardRef... Args>
constexpr VariantUnion<Head, Tail...>::VariantUnion(tfl::ValueTag<idx>, Args &&...pArgs) noexcept
requires(isValidIdx(idx)) {
  if constexpr (idx == 0_uint) {
    new (&mHead) Head{tfl::forward<Args>(pArgs)...};
  } else {
    new (&mTail) VariantUnion<Args...>{tfl::ValueTag<idx - 1>{},
                                       tfl::forward<Args>(pArgs)...};
  }
}

template <tfl::Value Head, tfl::Value... Tail>
constexpr void VariantUnion<Head, Tail...>::destroy(uint_t pIdx) noexcept {
  cfl::assert(isValidIdx(pIdx), "pIdx is not a valid index into this VariantUnion");
  if (pIdx == 0_uint) {
    mHead.~Head();
  } else {
    mTail.destroy(pIdx - 1);
    mTail.~VariantUnion<Tail...>();
  }
}

template <tfl::Value Head, tfl::Value... Tail>
template <uint_t idx, tfl::ForwardRef... Args>
constexpr void VariantUnion<Head, Tail...>::emplace(Args &&...pArgs) noexcept
    requires(isValidIdx(idx)) {
  if constexpr (idx == 0_uint) {
    new (&mHead) Head{tfl::forward<Args>(pArgs)...};
  } else {
    new (&mTail) VariantUnion<Tail...>{tfl::ValueTag<idx - 1>{},
                                       tfl::forward<Args>(pArgs)...};
  }
}

template <tfl::Value Head, tfl::Value... Tail>
template <uint_t idx>
[[nodiscard]] constexpr tfl::SelectType<idx, Head, Tail...> &
VariantUnion<Head, Tail...>::get() &noexcept
    requires(isValidIdx(idx)) {
  if constexpr (idx == 0) {
    return mHead;
  } else {
    return mTail.template get<idx - 1>();
  }
}

template <tfl::Value Head, tfl::Value... Tail>
template <uint_t idx>
[[nodiscard]] constexpr const tfl::SelectType<idx, Head, Tail...> &
VariantUnion<Head, Tail...>::get() const &noexcept
    requires(isValidIdx(idx)){
  return get<idx>();
}

template <tfl::Value Head> union VariantUnion<Head> final {
private:
  Head mHead;

public:
  template <uint_t idx, tfl::ForwardRef... Args>
  requires(idx == 0) constexpr VariantUnion(tfl::ValueTag<idx>,
                                            Args &&...pArgs) noexcept;
  constexpr ~VariantUnion() noexcept;

  constexpr VariantUnion() noexcept = delete;
  constexpr VariantUnion(const VariantUnion &) noexcept = delete;
  constexpr VariantUnion(VariantUnion &&) noexcept = delete;
  constexpr VariantUnion &operator=(const VariantUnion &) &noexcept = delete;
  constexpr VariantUnion &operator=(VariantUnion &&) &noexcept = delete;

  template <uint_t idx>
  [[nodiscard]] constexpr Head &get() &noexcept;
  
  template <uint_t idx>
  [[nodiscard]] constexpr const Head &get() const &noexcept;
  constexpr void destroy(uint_t pIdx) noexcept;
};

template <tfl::Value Head>
constexpr VariantUnion<Head>::~VariantUnion() noexcept {}

template <tfl::Value Head>
template <uint_t idx, tfl::ForwardRef... Args>
requires(idx == 0) constexpr VariantUnion<Head>::VariantUnion(
    tfl::ValueTag<idx>, Args &&...pArgs) noexcept {
  new (&mHead) Head{tfl::forward<Args>(pArgs)...};
}

template <tfl::Value Head>
constexpr void VariantUnion<Head>::destroy(uint_t) noexcept {
  mHead.~Head();
}

template <tfl::Value Head>
template <uint_t idx>
[[nodiscard]] constexpr Head &VariantUnion<Head>::get() &noexcept {
  return mHead;
}

template <tfl::Value Head>
template <uint_t idx>
[[nodiscard]] constexpr const Head &VariantUnion<Head>::get() const &noexcept {
  return mHead;
}

} // namespace
} // namespace ezs::adt

export
namespace ezs::adt {
template <tfl::Value... Ts> class Variant final {
private:
  [[no_unique_address]] VariantUnion<Ts...> mUnion;
  [[no_unique_address]] uint_t mActiveIdx;

public:
  template <uint_t idx, tfl::ForwardRef... Args>
  constexpr Variant(tfl::ValueTag<idx>, Args &&...pArgs) noexcept;
  constexpr Variant() noexcept = delete;
  constexpr Variant(const Variant &) noexcept = delete;
  constexpr Variant(Variant &&) noexcept = delete;
  constexpr Variant &operator=(const Variant &) &noexcept = delete;
  constexpr Variant &operator=(Variant &&) &noexcept = delete;
  constexpr ~Variant() noexcept;

  template <uint_t idx>
  [[nodiscard]] constexpr tfl::SelectType<idx, Ts...> &get() &noexcept;
  template <uint_t idx>
  [[nodiscard]] constexpr const tfl::SelectType<idx, Ts...> &
  get() const &noexcept;
  template <uint_t idx, tfl::ForwardRef... Args>
  constexpr void emplace(Args &&...pArgs) noexcept;

 private:
  void assertIsActiveIdx(uint_t pIdx) const noexcept;
};

template <tfl::Value... Ts>
void Variant<Ts...>::assertIsActiveIdx(uint_t pIdx) const noexcept {
  std::string message = "Cannot access variant with non-active index " + std::to_string(pIdx) +
      ". The active index is " + std::to_string(mActiveIdx)+ ".";
  cfl::assert(pIdx == mActiveIdx, message);
}

template <tfl::Value... Ts>
template <uint_t idx>
[[nodiscard]] constexpr tfl::SelectType<idx, Ts...> &
Variant<Ts...>::get() &noexcept {
  assertIsActiveIdx(idx);
  return mUnion.template get<idx>();
}

template <tfl::Value... Ts>
template <uint_t idx>
[[nodiscard]] constexpr const tfl::SelectType<idx, Ts...> &
Variant<Ts...>::get() const &noexcept {
  assertIsActiveIdx(idx);
  return mUnion.template get<idx>();
}

template <tfl::Value... Ts>
template <uint_t idx, tfl::ForwardRef... Args>
constexpr void Variant<Ts...>::emplace(Args &&...pArgs) noexcept {
  mUnion.destroy(mActiveIdx);
  mUnion.template emplace<idx>(tfl::forward<Args>(pArgs)...);
  mActiveIdx = idx;
}

template <tfl::Value... Ts>
template <uint_t idx, tfl::ForwardRef... Args>
constexpr Variant<Ts...>::Variant(tfl::ValueTag<idx>, Args &&...pArgs) noexcept
    : mUnion{tfl::ValueTag<idx>{}, tfl::forward<Args>(pArgs)...}, mActiveIdx{
                                                                      idx} {}

template <tfl::Value... Ts> constexpr Variant<Ts...>::~Variant() noexcept {
  mUnion.destroy(mActiveIdx);
}
} // namespace ezs::adt
