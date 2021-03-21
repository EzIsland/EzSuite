export module ezs.adt.Tuple;
import ezs.tfl.Value;
import ezs.tfl.ForwardRefOf;
import ezs.tfl.ForwardRef;
import ezs.tfl.forward;
import ezs.uint_t;
import ezs.tfl.SelectType;
import ezs.tfl.move;
import ezs.tfl.InstantiationOf;
import ezs.tfl.IndexSequence;
import ezs.tfl.ConstructibleFrom;
import ezs.adt.ForwardingTuple;

#include "ezs/adt/NOT_STANDARD_LAYOUT.hpp"

namespace ezs::adt {

export struct ConstructInPlace {};

template <tfl::Value HeadElement, tfl::Value... TailElements>
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
  template <tfl::ForwardRefOf<HeadElement> HeadArg,
            tfl::ForwardRefOf<TailElements>... TailArgs>
  constexpr explicit TupleHelper(HeadArg &&pHeadArg, TailArgs &&... pTailArgs)
      : mHead(tfl::forward<HeadArg>(pHeadArg)),
        mTail(tfl::forward<TailArgs>(pTailArgs)...) {}

  template<typename... Ts,
           tfl::InstantiationOf<ForwardingTuple>... Tail>
  requires(tfl::ConstructibleFrom<HeadElement, Ts...>)
  [[nodiscard]] constexpr explicit TupleHelper(
      ConstructInPlace,
      const ForwardingTuple<Ts...>& pHead,
      const Tail&... pTail) noexcept
      : TupleHelper(ConstructInPlace{}, pHead, tfl::MakeIndexSequenceFor<Ts...>{}, pTail...) {
  }

  template<typename... Ts,
           uint_t... idx,
           tfl::InstantiationOf<ForwardingTuple>... Tail>
  requires(tfl::ConstructibleFrom<HeadElement, Ts...>)
  [[nodiscard]] constexpr explicit TupleHelper(
      ConstructInPlace,
      const ForwardingTuple<Ts...>& pHead,
      tfl::IndexSequence<idx...>,
      const Tail&... pTail)
      : mHead{pHead.template get<idx>()...},
        mTail{ConstructInPlace{}, pTail...} {
  }

  // Retrieves the element by its index.
  template <uint_t idx>
  [[nodiscard]] constexpr tfl::SelectType<idx, HeadElement,
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
  [[nodiscard]] constexpr const tfl::SelectType<idx, HeadElement,
                                                 TailElements...> &
  get() const &noexcept {
    if constexpr (idx == 0) {
      return mHead;
    } else {
      return mTail.template get<idx - 1>();
    }
  }

private:
  [[no_unique_address]] HeadElement mHead;
  [[no_unique_address]] TupleHelper<TailElements...> mTail;
};

template <tfl::Value HeadElement>
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
  template <tfl::ForwardRefOf<HeadElement> HeadArg>
  constexpr explicit TupleHelper(HeadArg &&pHeadArg)
      : mHead(tfl::forward<HeadArg>(pHeadArg)) {}

  template<typename... Ts>
  requires(tfl::ConstructibleFrom<HeadElement, Ts...>)
  [[nodiscard]] constexpr explicit TupleHelper(
      ConstructInPlace,
      const ForwardingTuple<Ts...>& pHead) noexcept
      : TupleHelper(ConstructInPlace{}, pHead, tfl::MakeIndexSequenceFor<Ts...>{}) { }

  template<typename... Ts,
           uint_t... idx>
  requires(tfl::ConstructibleFrom<HeadElement, Ts...>)
  [[nodiscard]] constexpr explicit TupleHelper(
      ConstructInPlace,
      const ForwardingTuple<Ts...>& pHead,
      tfl::IndexSequence<idx...>) : mHead{pHead.template get<idx>()...} { }

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


export template <tfl::Value... Elements> class Tuple final {
public:
  Tuple() = delete;
  
  template<tfl::InstantiationOf<ForwardingTuple>... ForwardingTuples>
  [[nodiscard]] constexpr Tuple(ConstructInPlace, const ForwardingTuples&... pArgs) noexcept
      : mTuple(ConstructInPlace{}, pArgs...) {
  }
  
  [[nodiscard]] constexpr Tuple(const Tuple &) noexcept = default;
  [[nodiscard]] constexpr Tuple(Tuple &&) noexcept = default;
  constexpr Tuple &operator=(const Tuple &) &noexcept = default;
  constexpr Tuple &operator=(Tuple &&) &noexcept = default;

  constexpr ~Tuple() noexcept = default;

  template <tfl::ForwardRefOf<Elements>... Args>
  explicit constexpr Tuple(Args &&... pArgs) noexcept
      : mTuple(tfl::forward<Args>(pArgs)...) {}

  template <uint_t idx> [[nodiscard]] constexpr auto &get() & noexcept { return mTuple.template get<idx>(); }

  template <uint_t idx> [[nodiscard]] constexpr const auto &get() const& { return get<idx>(); }

private:
  TupleHelper<Elements...> mTuple;
};
} // namespace ezs::adt

