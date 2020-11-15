export module ezs.adt.Tuple;
import ezs.type.Value;
import ezs.type.ForwardRefOf;
import ezs.type.ForwardRef;
import ezs.type.forward;
import ezs.uint_t;
import ezs.type.SelectType;

#include "ezs/adt/NOT_STANDARD_LAYOUT.hpp"

namespace ezs::adt {

template <type::Value HeadElement, type::Value... TailElements>
class TupleHelper final {
public:
  // Deleted default ctor
  TupleHelper() = delete;

  // Default copy/move assgn/ctors dtor
  [[nodiscard]] constexpr TupleHelper(const TupleHelper &) noexcept = default;
  [[nodiscard]] constexpr TupleHelper(TupleHelper &&) noexcept = default;
  constexpr TupleHelper &operator=(const TupleHelper &) &noexcept = default;
  constexpr TupleHelper &operator=(TupleHelper &&) &noexcept = default;
  constexpr ~TupleHelper() noexcept = default;

  // Construct each element of tuple via forwarding reference.
  template <type::ForwardRefOf<HeadElement> HeadArg,
            type::ForwardRefOf<TailElements>... TailArgs>
  constexpr explicit TupleHelper(HeadArg &&pHeadArg, TailArgs &&... pTailArgs)
      : mHead(type::forward<HeadArg>(pHeadArg)),
        mTail(type::forward<TailArgs>(pTailArgs)...) {}

  // Retrieves the element by its index.
  template <uint_t idx>
  [[nodiscard]] constexpr type::SelectType<idx, HeadElement,
                                           TailElements...> &
      get() &
      noexcept {
    if constexpr (idx == 0) {
      return mHead;
    } else {
      return mTail.template get<idx - 1>();
    }
  }

  // Const version of get<idx>()
  template <uint_t idx>
  [[nodiscard]] constexpr const type::SelectType<idx, HeadElement,
                                                 TailElements...> &
  get() const &noexcept {
    if constexpr (idx == 0) {
      return mHead;
    } else {
      return mTail.template get<idx - 1>();
    }
  }

private:
  HeadElement mHead;
  TupleHelper<TailElements...> mTail;
};

template <type::Value HeadElement>
class TupleHelper<HeadElement> final {
public:
  // Deleted default ctor
  TupleHelper() = delete;

  // Default copy/move assgn/ctors dtor
  [[nodiscard]] constexpr TupleHelper(const TupleHelper &) noexcept = default;
  [[nodiscard]] constexpr TupleHelper(TupleHelper &&) noexcept = default;
  constexpr TupleHelper &operator=(const TupleHelper &) &noexcept = default;
  constexpr TupleHelper &operator=(TupleHelper &&) &noexcept = default;
  constexpr ~TupleHelper() noexcept = default;

  // Construct each element of tuple via forwarding reference.
  template <type::ForwardRefOf<HeadElement> HeadArg>
  constexpr explicit TupleHelper(HeadArg &&pHeadArg)
      : mHead(type::forward<HeadArg>(pHeadArg)) {}

  // Retrieves the element by its index.
  template <uint_t idx>
  [[nodiscard]] constexpr HeadElement& get() & noexcept {
    return mHead;
  }

  // Const version of get<idx>()
  template <uint_t idx>
  [[nodiscard]] constexpr const HeadElement& get() const &noexcept {
    return mHead;
  }

private:
  HeadElement mHead;
};

export template <type::Value... Elements> class Tuple final {
public:
  Tuple() = delete;
  void operator=(const Tuple &&) = delete;
  Tuple(const Tuple &&) = delete;

  
  [[nodiscard]] constexpr Tuple(const Tuple &) noexcept = default;
  [[nodiscard]] constexpr Tuple(Tuple &&) noexcept = default;
  constexpr Tuple &operator=(const Tuple &) &noexcept = default;
  constexpr Tuple &operator=(Tuple &&) &noexcept = default;

  constexpr ~Tuple() noexcept = default;

  template <type::ForwardRefOf<Elements>... Args>
  explicit constexpr Tuple(Args &&... pArgs) noexcept
      : mTuple(type::forward<Args>(pArgs)...) {}

  template <uint_t idx> [[nodiscard]] constexpr auto &get() & noexcept { return mTuple.template get<idx>(); }

  template <uint_t idx> [[nodiscard]] constexpr const auto &get() const& { return get<idx>(); }

private:
  TupleHelper<Elements...> mTuple;
};
} // namespace ezs::adt

