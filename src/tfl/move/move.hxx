export module ezs.tfl.move;
import ezs.tfl.RemoveLValueRef;
import ezs.tfl.ForwardRef;
namespace ezs::tfl {
export template<ForwardRef T>
constexpr RemoveLValueRef<T>&& move(T&& pObject) noexcept {
  return static_cast<RemoveLValueRef<T>&&>(pObject);
}
} // namespace



