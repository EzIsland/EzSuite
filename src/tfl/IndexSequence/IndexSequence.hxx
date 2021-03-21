export module ezs.tfl.IndexSequence;

import ezs.uint_t;

namespace ezs::tfl {

export
template<uint_t... Idx>
struct IndexSequence { };

template<uint_t Head, uint_t... Tail>
class MakeIndexSequenceImpl {
 public:
  using Type = typename MakeIndexSequenceImpl<Head-1_uint, Head, Tail...>::Type;
};

template <uint_t... Tail>
class MakeIndexSequenceImpl<0_uint, Tail...> {
 public:
  using Type = IndexSequence<0_uint, Tail...>;
};

export template <uint_t idx>
using MakeIndexSequence = typename MakeIndexSequenceImpl<idx-1_uint>::Type;

export
template<typename... Ts>
using MakeIndexSequenceFor = MakeIndexSequence<sizeof...(Ts)>;

} // namespace ezs::tfl
