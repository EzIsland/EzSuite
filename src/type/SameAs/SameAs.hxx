export module ezs.type.SameAs;

namespace ezs::type {

template <typename T, typename U> constexpr bool isSame = false;

template <typename T> constexpr bool isSame<T, T> = true;

export template<typename T, typename U> concept SameAs = isSame<T, U>;

} // namespace 
