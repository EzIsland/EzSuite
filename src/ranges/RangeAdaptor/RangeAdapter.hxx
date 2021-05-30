export module ezs.ranges.RangeAdaptor;

namespace ezs::ranges {
  template<typename T, typename Elem>
  concept RangeAdaptor = requires(T pAdaptor, auto Range pRange) {
    { pAdaptor(pRange) } -> Range;
  }
}
