export module ezs.ranges.Iterator;

import ezs.tfl.SameAs;

export
namespace ezs::ranges {
  template<typename T, typename Elem>
  concept Iterator = requires(T pIterator) {
    { *pIterator } -> tfl::SameAs<Elem>;
    { pIterator } -> tfl::SameAs<bool>;
  };
}
