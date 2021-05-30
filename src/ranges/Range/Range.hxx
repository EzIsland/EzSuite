export module ezs.ranges.Range;

import ezs.ranges.Iterator;

namespace ezs::ranges {
export
template<typename T, typename Elem>
concept Range = requires(T pRange) {
  { pRange.iter() } -> Iterator<Elem>;
};

}
