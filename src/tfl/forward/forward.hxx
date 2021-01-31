export module ezs.tfl.forward;
import ezs.tfl.NonDeduced;
import ezs.tfl.ForwardRef;
import ezs.tfl.LValueRef;

export
namespace ezs::tfl {
template <ForwardRef T>
constexpr T&& forward(NonDeduced<T>& pObject) noexcept {
  if constexpr(LValueRef<T>) {
    return pObject;
  } else {
    return static_cast<T&&>(pObject);
  }
} 
} // namespace 
