export module ezs.ranges.IndexedRange;

import ezs.ranges.BidirectionalRange;
import ezs.tfl.SameAs;
import ezs.uint_t;

// export
// namespace ezs::ranges {
//   template<typename T, typename Elem>
//   concept IndexedRange = BidirectionalRange<T, Elem> && requires(T pIndexedRange, uint_t pIndex) {
//     { pIndexedRange[pIndex] } -> tfl::SameAs<Elem>;
//   };
// }
