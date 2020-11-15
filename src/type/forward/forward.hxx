export module ezs.type.forward;
import ezs.type.NonDeduced;
import ezs.type.ForwardRef;
import ezs.type.LValueRef;

export
namespace ezs::type {
template <ForwardRef T>
constexpr T&& forward(NonDeduced<T>& pObject) noexcept {
  if constexpr(LValueRef<T>) {
    return pObject;
  } else {
    return static_cast<T&&>(pObject);
  }
} 
} // namespace 
