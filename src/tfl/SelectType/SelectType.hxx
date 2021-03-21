export module ezs.tfl.SelectType;
import ezs.uint_t;
namespace ezs::tfl {

template <uint_t idx, typename Head, typename... Tail>
requires (idx <= sizeof...(Tail) )
struct SelectTypeHelper {
  using Type = typename SelectTypeHelper<idx - 1, Tail...>::Type;
};

template <typename Head, typename... Tail>
struct SelectTypeHelper<0, Head, Tail...> {
  using Type = Head;
};

export template <uint_t idx, typename... Ts>
using SelectType = typename SelectTypeHelper<idx, Ts...>::Type;

} // namespace 
