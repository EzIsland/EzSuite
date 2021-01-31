export module ezs.tfl.RemoveVolatile;

namespace ezs::tfl {

template <typename T> struct RemoveVolatileImpl { using Type = T; };

template <typename T> struct RemoveVolatileImpl<volatile T> { using Type = T; };

export template<typename T> using RemoveVolatile = typename RemoveVolatileImpl<T>::Type;
} // namespace 
