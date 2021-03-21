///
/// \file Implementation of ezs.adt.Vector
///
export module ezs.adt.Vector;

import ezs.adt.ForwardingTuple;
import ezs.cfl.assert;
import ezs.tfl.ConstructibleFrom;
import ezs.tfl.CopyConstructible;
import ezs.tfl.CopyAssignable;
import ezs.tfl.forward;
import ezs.tfl.ForwardConstructibleFrom;
import ezs.tfl.ForwardRef;
import ezs.tfl.ForwardRefOf;
import ezs.tfl.InstantiationOf;
import ezs.tfl.Value;
import ezs.tfl.move;
import ezs.uint_t;

export
namespace ezs::adt {

///
/// \brief A Vector is a dynamically sized contiguous array.
/// Properties:
/// 1. CopyConstructible if T is CopyConstructible
/// 2. CopyAssignable if T is CopyAssignable
///
template <tfl::Value T>
class Vector {
 public:
  ///
  /// \brief Constructs a vector containing zero elements and zero capacity
  /// known as an empty vector.
  ///
  [[nodiscard]] constexpr explicit Vector() noexcept;

  ///
  /// \brief Constructs a vector containing N elements which are forward constructed
  /// from the N constructor arguments of type T.
  ///
  template<tfl::ForwardRefOf<T>... Args>
  [[nodiscard]] constexpr explicit Vector(Args&&...) noexcept
      requires(sizeof...(Args) > 0_uint);

  ///
  /// \brief Constructs a vector containing N elements which are in-place constructed
  /// from the N constructor arguments. Each constructor argument is a forwarding
  /// tuple which specifies the arguments to be forwarded to the corresponding
  /// element's constructor.
  ///
  template<tfl::InstantiationOf<adt::ForwardingTuple>... ForwardingTuples>
  [[nodiscard]] constexpr explicit Vector(const ForwardingTuples&...) noexcept
      requires(sizeof...(ForwardingTuples) > 0_uint);


  ///
  /// \brief Copy constructs this vector from another vector of identical type.
  /// This constructor only participates in overload resolution if T is
  /// itself copy constructible.
  ///
  [[nodiscard]] constexpr explicit Vector(const Vector&) noexcept
      requires(tfl::CopyConstructible<T>);

  ///
  /// \brief Move constructs this vector from another vector of identical type.
  ///
  [[nodiscard]] constexpr explicit Vector(Vector&&) noexcept;

  ///
  /// \brief Copy assigns this vector from another vector of identical type.
  /// This member function only participates in overload resolution if T is
  /// itself copy assignable.
  ///
  constexpr void operator=(const Vector&) & noexcept
      requires(tfl::CopyAssignable<T>);

  ///
  /// \brief Move assigns this vector from another vector of identical type.
  ///
  constexpr void operator=(Vector&&) & noexcept;

  ///
  /// \brief Destroys this vector and all elements contained within it.
  /// The order of element desctruction is not defined.
  ///
  constexpr ~Vector() noexcept;
  
  ///
  /// \brief Forward constructs a new element into the end of the vector,
  /// increasing the vector's capacity if necessary.
  ///
  template<tfl::ForwardRef... Args>
  constexpr void emplaceBack(Args&&... pArgs) noexcept
      requires(tfl::ForwardConstructibleFrom<T, Args...>);

  ///
  /// \brief Accesses the element at the specified index and returns a
  /// reference to it.
  ///
  [[nodiscard]] constexpr T& operator[](uint_t) & noexcept;

  ///
  /// \brief Access the element at the specified index and returns a const
  /// reference to it.
  ///
  [[nodiscard]] constexpr const T& operator[](uint_t) const& noexcept;

  ///
  /// \brief Disallow const rvalue-ref access to elements.
  ///
  constexpr const T& operator[](uint_t) const&& noexcept = delete;

  ///
  /// \brief Disallow rvalue-ref access to elements.
  ///
  constexpr T& operator[](uint_t) && noexcept = delete;

  ///
  /// \brief Returns the number of elements contained in this vector.
  ///
  [[nodiscard]] constexpr uint_t size() const noexcept;

 private:
  T* mData;
  uint_t mCapacity;
  uint_t mSize;

  ///
  /// \brief Reserves enough memory for at least pCapacity elements.
  ///
  constexpr void reserve(uint_t pCapacity) & noexcept;

  ///
  ///
  ///
  constexpr void grow(uint_t pCapacity) & noexcept;
};

template <tfl::Value T> [[nodiscard]] constexpr Vector<T>::Vector() noexcept
: mDa
eta(nullptr), mCapacity(0), mSize(0) { }

template <tfl::Value T>
template <tfl::ForwardRefOf<T>... Args>
[[nodiscard]] constexpr Vector<T>::Vector(Args &&... pArgs) noexcept
    requires(sizeof...(Args) > 0_uint) : Vector() {
  init(tfl::forward<Args>(pArgs)...);
}

template <tfl::Value T>
template <tfl::InstantiationOf<adt::ForwardingTuple>... ForwardingTuples>
[[nodiscard]] constexpr Vector<T>::Vector(const ForwardingTuples &...) noexcept
    requires(sizeof...(ForwardingTuples) > 0_uint) { }

template <tfl::Value T>
[[nodiscard]] constexpr Vector<T>::Vector(const Vector &) noexcept
    requires(tfl::CopyConstructible<T>) { }

template <tfl::Value T>
[[nodiscard]] constexpr Vector<T>::Vector(Vector &&) noexcept { }

template <tfl::Value T>
constexpr void Vector<T>::operator=(const Vector &) &noexcept
    requires(tfl::CopyAssignable<T>) { }

template <tfl::Value T> constexpr void Vector<T>::operator=(Vector &&) &noexcept { }

template <tfl::Value T> constexpr Vector<T>::~Vector() noexcept {
  delete mData;
}

template <tfl::Value T>
template <tfl::ForwardRef... Args>
constexpr void Vector<T>::emplaceBack(Args &&... pArgs) noexcept
    requires(tfl::ForwardConstructibleFrom<T, Args...>) {
  reserve(mSize+1);
  new (mData+mSize) T{pArgs...};
  ++mSize;
}

template <tfl::Value T>
[[nodiscard]] constexpr T &
Vector<T>::operator[](uint_t pIdx) &noexcept {
  cfl::assert(pIdx < mSize, "Vector index exceeds vector's size.");
  return mData[pIdx];
}

template <tfl::Value T>
[[nodiscard]] constexpr const T & Vector<T>::operator[](uint_t pIdx) const &noexcept {
  cfl::assert(pIdx < mSize, "Vector index exceeds vector's size.");
  return mData[pIdx];
}

template <tfl::Value T>
[[nodiscard]] constexpr uint_t Vector<T>::size() const noexcept {
  return mSize;
}

template<tfl::Value T>
constexpr void Vector<T>::reserve(uint_t pCapacity) & noexcept {
  if(pCapacity > mCapacity) {
    grow(pCapacity);
  }
}

template<tfl::Value T>
constexpr void Vector<T>::grow(uint_t pCapacity) & noexcept {
  T* newData = reinterpret_cast<T*>(::operator new(pCapacity));
  for(uint_t i = 0; i != mCapacity; ++i) {
    new (newData+i) T{tfl::move(mData[i])};
  }
  mData = newData;
  mCapacity = pCapacity;
}
} // namespace ezs::adt
