export module ezs.tfl.Volatile;

template <typename T>
constexpr bool isVolatile = false;

template <typename T>
constexpr bool isVolatile<volatile T> = true;

export
namespace ezs::tfl {

template <typename T>
concept Volatile = isVolatile<T>;

} // namespace 
