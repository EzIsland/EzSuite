export module ezs.ranges.Collection;

import ezs.tfl.SameAs;
import ezs.uint_t;

export
namespace ezs::ranges {
  template<typename T, typename Elem>
  concept Collection = requires(T pCollection, Elem pElem) {
    { pCollection.contains(pElem) } -> tfl::SameAs<bool>;
    { pCollection.size() } -> tfl::SameAs<uint_t>;
  };
}
