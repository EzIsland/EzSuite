export module ezs.ranges.BidirectionalRange;

import ezs.ranges.BidirectionalIterator;
import ezs.ranges.OrderedRange;

namespace ezs::ranges {
  template<typename T, typename Elem>
  concept BidirectionalRange = OrderedRange<T, Elem> && requires(T pBidirectionalRange, Elem pElem) {
    pBidirectionalRange.endIter() -> template BidrectionalIterator<Elem>;
    pBidirectionalRange.iter() -> template BidirectionalIterator<Elem>;
  };
};
