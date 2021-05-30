export module ezs.ranges.OrderedRange;

import ezs.ranges.Range;

export
namespace ezs::ranges {
  template<typename T, typename Elem>
  concept OrderedRange = Range<T, Elem>;
}
