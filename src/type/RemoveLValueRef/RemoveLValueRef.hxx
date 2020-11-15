export module ezs.type.RemoveLValueRef;

namespace ezs::type {

template <typename T> struct RemoveLValueRefImpl { using Type = T; };

template<typename T> struct RemoveLValueRefImpl<T&> { using Type = T; };

export template<typename T> using RemoveLValueRef = typename RemoveLValueRefImpl<T>::Type;

} // namespace 
