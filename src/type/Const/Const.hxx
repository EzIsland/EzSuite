export module ezs.type.Const;

namespace ezs::type {

template <typename T>
constexpr bool isConst = false;

template <typename T>
constexpr bool isConst<const T> = true;

export template <typename T>
concept Const = isConst<T>;

} // namespace 
