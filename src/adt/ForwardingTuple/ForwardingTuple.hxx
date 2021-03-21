export module ezs.adt.ForwardingTuple;
import ezs.tfl.ForwardRefOf;
import ezs.tfl.ForwardRef;
import ezs.tfl.Value;
import ezs.tfl.SelectType;
import ezs.tfl.SameAs;
import ezs.tfl.forward;
import ezs.uint_t;
namespace ezs::adt {

namespace {

template<tfl::ForwardRef Head, tfl::ForwardRef... Tail>
class ForwardingTupleHelper final {
 private:
  Head&& mHead;
  ForwardingTupleHelper<Tail...> mTail;

  [[nodiscard]] static constexpr bool isValidIdx(uint_t pIdx) noexcept;

 public:
  template<uint_t idx>
  [[nodiscard]] constexpr tfl::SelectType<idx, Head, Tail...>&& get() const noexcept
      requires(isValidIdx(idx));

  explicit constexpr ForwardingTupleHelper(Head&&, Tail&&...) noexcept;
  
  constexpr ~ForwardingTupleHelper() noexcept = default;
  
  constexpr ForwardingTupleHelper() noexcept = delete;
  constexpr ForwardingTupleHelper(const ForwardingTupleHelper&) noexcept = delete;
  constexpr ForwardingTupleHelper(ForwardingTupleHelper&&) noexcept = delete;
  constexpr ForwardingTupleHelper& operator=(const ForwardingTupleHelper&) & noexcept = delete;
  constexpr ForwardingTupleHelper& operator=(ForwardingTupleHelper&&) & noexcept = delete;
};

template<tfl::ForwardRef Head, tfl::ForwardRef... Tail>
[[nodiscard]] constexpr bool ForwardingTupleHelper<Head, Tail...>::isValidIdx(uint_t pIdx) noexcept {
  return pIdx <= sizeof...(Tail);
}

template<tfl::ForwardRef Head, tfl::ForwardRef... Tail>
constexpr ForwardingTupleHelper<Head, Tail...>::ForwardingTupleHelper(Head&& pHead, Tail&&... pTail)
    noexcept : mHead{tfl::forward<Head>(pHead)}, mTail{tfl::forward<Tail>(pTail)...} {
}

template<tfl::ForwardRef Head, tfl::ForwardRef... Tail>
template<uint_t idx>
constexpr tfl::SelectType<idx, Head, Tail...>&& ForwardingTupleHelper<Head, Tail...>::get() const noexcept requires(isValidIdx(idx)) {
  if constexpr(idx == 0_uint) {
    return tfl::forward<Head>(mHead);
  } else {
    return mTail.template get<idx - 1>();
  }
}

///////////////////////////////////////////////////////////////////////////

template<tfl::ForwardRef Head>
class ForwardingTupleHelper<Head> final {
 private:
  Head&& mHead;

  [[nodiscard]] static constexpr bool isValidIdx(uint_t pIdx) noexcept;

 public:
  template<uint_t idx>
  [[nodiscard]] constexpr Head&& get() const noexcept
      requires(isValidIdx(idx));

  explicit constexpr ForwardingTupleHelper(Head&&) noexcept;
  
  constexpr ~ForwardingTupleHelper() noexcept = default;
  
  constexpr ForwardingTupleHelper() noexcept = delete;
  constexpr ForwardingTupleHelper(const ForwardingTupleHelper&) noexcept = delete;
  constexpr ForwardingTupleHelper(ForwardingTupleHelper&&) noexcept = delete;
  constexpr ForwardingTupleHelper& operator=(const ForwardingTupleHelper&) & noexcept = delete;
  constexpr ForwardingTupleHelper& operator=(ForwardingTupleHelper&&) & noexcept = delete;
};

template<tfl::ForwardRef Head>
[[nodiscard]] constexpr bool ForwardingTupleHelper<Head>::isValidIdx(uint_t pIdx) noexcept {
  return pIdx == 0;
}

template<tfl::ForwardRef Head>
constexpr ForwardingTupleHelper<Head>::ForwardingTupleHelper(Head&& pHead)
    noexcept : mHead{tfl::forward<Head>(pHead)} {
}

template<tfl::ForwardRef Head>
template<uint_t idx>
constexpr Head&& ForwardingTupleHelper<Head>::get() const noexcept requires(isValidIdx(idx)) {
  return tfl::forward<Head>(mHead);
}
} // namespace
} // namespace ezs::adt

export
namespace ezs::adt {

///////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////

///
/// @brief A ForwardingTuple is a tuple of (l-value or r-value) references which preserve
/// the value category of the objects passed to its constructor. A
/// ForwardingTuple should not outlive the lifetime of any of the objects from
/// which it is constructed.
///
template <tfl::ForwardRef... Ts>
class ForwardingTuple final {
 private:
  ///
  /// @brief Implementation of the forwarding tuple as the recursive data structure
  /// ForwardingTupleHelper.
  ///
  ForwardingTupleHelper<Ts...> mForwardingTuple;

  ///
  /// @brief True if pIdx is a valid index into this tuple.
  ///
  [[nodiscard]] static constexpr bool isValidIdx(uint_t pIdx) noexcept;

  ///
  /// @brief Returns the number of elements contained in this tuple.
  ///
  [[nodiscard]] static constexpr uint_t size() noexcept;

  ///
  /// @brief Constructs this ForwardingTuple from a set of references 
  ///
  constexpr ForwardingTuple(Ts&&...) noexcept;

 public:
  constexpr ~ForwardingTuple() noexcept = default;  
  constexpr ForwardingTuple() noexcept = delete;


  constexpr ForwardingTuple(const ForwardingTuple&) noexcept = delete;
  constexpr ForwardingTuple(ForwardingTuple&&) noexcept = delete;
  constexpr ForwardingTuple& operator=(const ForwardingTuple&) & noexcept = delete;
  constexpr ForwardingTuple& operator=(ForwardingTuple&&) & noexcept = delete;

  template<uint_t idx>
  constexpr tfl::SelectType<idx, Ts...>&& get() const noexcept
      requires(isValidIdx(idx));

  template<tfl::ForwardRef... Args>
  friend constexpr ForwardingTuple<Args...> forwardAsTuple(Args&&... pArgs) noexcept;
};

template<tfl::ForwardRef... Ts>
[[nodiscard]] constexpr bool ForwardingTuple<Ts...>::isValidIdx(uint_t pIdx) noexcept {
  return pIdx <= sizeof...(Ts) - 1;
}

template<tfl::ForwardRef... Ts>
[[nodiscard]] constexpr uint_t ForwardingTuple<Ts...>::size() noexcept {
  return sizeof...(Ts);
}

template<tfl::ForwardRef... Ts>
constexpr ForwardingTuple<Ts...>::ForwardingTuple(Ts&&... pArgs) noexcept
    : mForwardingTuple{tfl::forward<Ts>(pArgs)...} {
}

template<tfl::ForwardRef... Ts>
template<uint_t idx>
constexpr tfl::SelectType<idx, Ts...>&& ForwardingTuple<Ts...>::get() const noexcept
    requires(isValidIdx(idx)) {
  return mForwardingTuple.template get<idx>();
}

template<tfl::ForwardRef... Args>
constexpr ForwardingTuple<Args...> forwardAsTuple(Args&&... pArgs) noexcept {
  return ForwardingTuple<Args...>{tfl::forward<Args>(pArgs)...};
}

} // namespace ezs::adt
