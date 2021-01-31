export module ezs.tfl.Const;

namespace ezs::tfl {

template <typename T>
constexpr bool isConst = false;

template <typename T>
constexpr bool isConst<const T> = true;

export template <typename T>
concept Const = isConst<T>;

} // namespace 
