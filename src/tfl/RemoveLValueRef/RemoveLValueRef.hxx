export module ezs.tfl.RemoveLValueRef;

namespace ezs::tfl {

template <typename T> struct RemoveLValueRefImpl { using Type = T; };

template<typename T> struct RemoveLValueRefImpl<T&> { using Type = T; };

export template<typename T> using RemoveLValueRef = typename RemoveLValueRefImpl<T>::Type;

} // namespace 
