export module ezs.type.Volatile;

template <typename T>
constexpr bool isVolatile = false;

template <typename T>
constexpr bool isVolatile<volatile T> = true;

export
namespace ezs::type {

template <typename T>
concept Volatile = isVolatile<T>;

} // namespace 
