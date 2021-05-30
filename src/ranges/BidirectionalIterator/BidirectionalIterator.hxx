export module ezs.ranges.BidirectionalIterator;

namespace ezs::ranges {
  template<typename T, typename Elem>
  concept BidirectionalIterator = requires(T pIterator) {
    --pIterator;
    ++pIterator;
  };
}
