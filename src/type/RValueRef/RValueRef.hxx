export module ezs.type.RValueRef;

template <typename T> constexpr bool isRValueRef = false;

template <typename T> constexpr bool isRValueRef<T&&> = true;

export
namespace ezs::type {
template <typename T>
concept RValueRef = isRValueRef<T>;
} // namespace 
