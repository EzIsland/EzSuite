export module ezs.type.RemoveRValueRef;

namespace ezs::type {

template <typename T> struct RemoveRValueRefImpl { using Type = T; };

template<typename T> struct RemoveRValueRefImpl<T&&> { using Type = T; };

export template<typename T> using RemoveRValueRef = typename RemoveRValueRefImpl<T>::Type;

} // namespace 
