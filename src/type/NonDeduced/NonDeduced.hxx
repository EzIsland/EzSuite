export module ezs.type.NonDeduced;
namespace ezs::type {

template <typename T> struct Identity { using Type = T; };

export template<typename T> using NonDeduced = typename Identity<T>::Type;

} // namespace ezs::type
