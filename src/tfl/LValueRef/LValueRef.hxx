export module ezs.tfl.LValueRef;

template <typename T> constexpr bool isLValueRef = false;

template <typename T> constexpr bool isLValueRef<T&> = true;

export
namespace ezs::tfl {
template <typename T>
concept LValueRef = isLValueRef<T>;
} // namespace 
