export module ezs.tfl.RValueRef;

template <typename T> constexpr bool isRValueRef = false;

template <typename T> constexpr bool isRValueRef<T&&> = true;

export
namespace ezs::tfl {
template <typename T>
concept RValueRef = isRValueRef<T>;
} // namespace 
