export module ezs.type.move;
import ezs.type.RemoveLValueRef;
import ezs.type.ForwardRef;
namespace ezs::type {
export template<ForwardRef T>
constexpr RemoveLValueRef<T>&& move(T&& pObject) noexcept {
  return static_cast<RemoveLValueRef<T>&&>(pObject);
}
} // namespace



