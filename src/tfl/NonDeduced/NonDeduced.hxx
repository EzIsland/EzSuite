export module ezs.tfl.NonDeduced;
namespace ezs::tfl {

template <typename T> struct Identity { using Type = T; };

export template<typename T> using NonDeduced = typename Identity<T>::Type;

} // namespace ezs::tfl
