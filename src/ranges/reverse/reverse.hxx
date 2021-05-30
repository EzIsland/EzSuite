export module ezs.ranges.reverse;

import ezs.ranges.BidirectionalRange;
import ezs.ranges.BidirectonalIterator;

export
namespace ezs::ranges {

  template<typename Elem, BidirectionalIterator<Elem> BaseIterator>
  class ReversedIterator {

    void operator++() {
      --mBaseIterator;
    }

    void operator--() {
      ++mBaseIterator;
    }

  private:
    BaseIterator mBaseIterator;
    
    ReversedIterator(const BaseIterator& pBaseIterator)
      : mBaseIterator(pBaseIterator) {
    }
  };
  
  template<typename Elem, BidirectionalRange<Elem> BaseRange>
  class ReversedRange {
  private:
    const BaseRange& mRange;

    ReversedRange(const BaseRange& pRange)
      : BaseRange{pRange} {
    }

  public:
    ReversedIterator<BaseRange::Iterator> iter() {
      return ReversedIterator<Elem, BaseRange>{--mRange.end()};
    }

    ReversedIterator<BaseRange::Iterator> endIter() {
      return ReversedIterator<Elem, BaseRange>{mRange.begin()};
    }
  }

  template<typename Elem, BidirectionalRange BaseRange>
  reverse(const BaseRange& pRange) -> auto BidirectionalRange {
      return ReversedRange<pRange::ElemType, BaseRange>{pRange};
  }
}
