export module ezs.tfl.SameAs;

namespace ezs::tfl {

template <typename T, typename U> constexpr bool isSame = false;

template <typename T> constexpr bool isSame<T, T> = true;

export template<typename T, typename U> concept SameAs = isSame<T, U>;

} // namespace 
