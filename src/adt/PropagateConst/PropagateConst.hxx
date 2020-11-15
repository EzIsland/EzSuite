export module ezs.adt.PropagateConst;

import ezs.uint_t;
import ezs.adt.ObjectPtr;
import ezs.adt.ArrayPtr;
import ezs.type.forward;
import ezs.type.ForwardRefOf;
import ezs.type.move;
import ezs.type.ForwardRef;

export
namespace ezs::adt {

template <typename T> class PropagateConst final { };

template <ObjectPtr T> class PropagateConst<T> final {
 public:
  using ObjectType = typename T::ObjectType;
  PropagateConst() = delete;
  PropagateConst(const PropagateConst<T>&) = delete;
  PropagateConst<T>& PropagetConst(const PropagateConst<T>&) = delete;

  template <type::ForwardRef... Args>
  [[nodiscard]] explicit constexpr PropagateConst(Args &&... pArgs) noexcept
      : mPtr(type::forward<Args>(pArgs)...) {}

  template<type::ForwardRefOf<T> U>
  [[nodiscard]] explicit constexpr PropagateConst(U&& pPtr) noexcept
      : mPtr(type::forward<U>(pPtr)) { }
  
  [[nodiscard]] explicit constexpr PropagateConst(PropagateConst<T>&& pOther) noexcept
      : mPtr(type::move(pOther.mPtr)) { }
  
  constexpr PropagateConst<T>& operator=(PropagateConst<T>&& pOther) & noexcept {
    mPtr = type::move(pOther.mPtr);
  }

  [[nodiscard]] constexpr ObjectType& operator*() noexcept {
    return *mPtr;
  }
  
  [[nodiscard]] constexpr ObjectType* operator->() noexcept {
    return mPtr.operator->();
  }
  
  [[nodiscard]] constexpr const ObjectType& operator*() const noexcept {
    return *mPtr;
  }
  
  [[nodiscard]] constexpr const ObjectType* operator->() const noexcept {
    return mPtr.operator->();
  }
  
 private:
  T mPtr;
};

// template<ArrayPtrLike Pointer> class PropagateConst<Pointer> final {
//  public:
//   using Pointee = typename Pointer::Pointee;
//   PropagateConst() = delete;
//   PropagateConst(const PropagateConst<Pointer>&) = delete;
//   PropagateConst<Pointer>& PropagetConst(const PropagateConst<Pointer>&) = delete;

//   [[nodiscard]] constexpr PropagateConst(uint_t) noexcept;
//   [[nodiscard]] constexpr PropagateConst(PropagateConst<Pointer>&&) noexcept;
//   constexpr PropagateConst<Pointer>& operator=(PropagateConst<Pointer>&&) & noexcept;

//   [[nodiscard]] constexpr Pointee& operator[](uint_t) noexcept;
//   [[nodiscard]] constexpr const Pointee& operator[](uint_t) const noexcept;
  
//  private:
//   Pointer mPtr;
// };

} // namespace ezs::adt
