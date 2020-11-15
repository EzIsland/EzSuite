export module ezs.type.LValueRef;

template <typename T> constexpr bool isLValueRef = false;

template <typename T> constexpr bool isLValueRef<T&> = true;

export
namespace ezs::type {
template <typename T>
concept LValueRef = isLValueRef<T>;
} // namespace 
