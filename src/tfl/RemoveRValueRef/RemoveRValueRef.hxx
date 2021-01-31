export module ezs.tfl.RemoveRValueRef;

namespace ezs::tfl {

template <typename T> struct RemoveRValueRefImpl { using Type = T; };

template<typename T> struct RemoveRValueRefImpl<T&&> { using Type = T; };

export template<typename T> using RemoveRValueRef = typename RemoveRValueRefImpl<T>::Type;

} // namespace 
