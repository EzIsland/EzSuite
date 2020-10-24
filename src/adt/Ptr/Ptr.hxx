///
/// \file Ptr.hxx
/// \brief Module interface file of ezs::adt::Ptr class.
///
export module ezs.adt.Ptr;

import ezs.adt.Value;

export namespace ezs::adt {

///
/// \brief Const propagating pointer type wrapper.
///
/// ezs::adt::Ptr is a const propagating wrapper for pointer types.
/// It can be used as a drop in replacement for raw pointers in most situations.
/// Unlike raw pointers, if a Ptr object is itself const then the pointed to
/// object can only be accessed as const.
///
/// The Ptr class should not contain sentinal values to indicate a lack of a
/// pointee. While it is admissable for Ptr to store a nullptr, such a value
/// does not have any special sentinal meaning. Clients can generally assume
/// that Ptr points to a valid object unless it is in a moved-from state.
///
/// \tparam Pointee The pointed to type which Ptr aliases. Note that Pointee
/// refers to the underlying type which would be retrieved by dereferencing Ptr.
/// Pointee must satisfy the concept ezs::adt::Value.
/// The template parameter may be an incomplete type.
///
template <Value Pointee> class Ptr final {
public:
  ///
  /// \brief Deleted default constructor.
  ///
  /// There is no meaningful default value for a Ptr type.
  ///
  Ptr() = delete;

  ///
  /// \brief Constructs a Ptr object from a raw pointer.
  ///
  /// The resulting Ptr object is a wrapper for the input pointer.
  ///
  /// \param pPtr A pointer whose pointee this constructed Ptr will alias.
  ///
  explicit constexpr Ptr(Pointee *pPtr) noexcept;

  ///
  /// \brief Deleted copy constructor.
  ///
  /// A Ptr type cannot be copied in order to disallow:
  /// 1. Removing the constness of a const Ptr by copying it to a non-const Ptr.
  /// 2. Inadvertantly aliasing the pointee by shallow copying a Ptr.
  ///
  constexpr Ptr(const Ptr<Pointee> &) noexcept = delete;

  ///
  /// \brief Move constructs a Ptr.
  ///
  /// The constructed Ptr object aliases the pointee of the moved-from Ptr.
  /// \note The behavior is undefined if the moved-from Ptr is accessed in any
  /// way except by its assignment operator.
  ///
  /// \param pOther The Ptr whose pointee will be aliased by the constructed
  /// Ptr. pOther is left in a moved-from state after assignment.
  ///
  constexpr Ptr(Ptr<Pointee> &&pOther) noexcept;

  ///
  /// \brief Deleted copy assignment.
  ///
  /// A Ptr type cannot be copy assigned in order to disallow:
  /// 1. Removing the constness of a const Ptr by copying it to a non-const Ptr.
  /// 2. Inadvertantly aliasing the pointee by shallow copying a Ptr.
  ///
  constexpr Ptr<Pointee> &operator=(const Ptr<Pointee> &) &noexcept = delete;

  ///
  /// \brief Move assigns a Ptr.
  ///
  /// The assigned Ptr object aliases the pointee of the moved-from Ptr.
  /// \note The behavior is undefined if the moved-from Ptr is accessed in any
  /// way except by its assignment operator.
  ///
  /// \param pOther The Ptr whose pointee will be aliased by this Ptr after
  /// assignment. pOther is left in a moved-from state after assignment.
  ///
  constexpr Ptr<Pointee> &operator=(Ptr<Pointee> &&pOther) & noexcept;

  ///
  /// \brief Default destructor.
  ///
  constexpr ~Ptr() noexcept = default;

  ///
  /// \brief This overloaded member access operator provides const access to
  /// a pointee's members.
  ///
  /// This overload is chosen when the Ptr object is itself const.
  ///
  [[nodiscard]] constexpr const Pointee *operator->() const noexcept;

  ///
  /// \brief This overloaded member access operator provides non-const access to
  /// a pointee's members.
  ///
  /// This overload is only chosen when the Ptr object is not const.
  ///
  [[nodiscard]] constexpr Pointee *operator->() noexcept;

  ///
  /// \brief This overloaded dereference operator provides const only access to
  /// the pointee.
  ///
  /// The overload is chosen only when the Ptr object is const.
  ///
  [[nodiscard]] constexpr const Pointee &operator*() const noexcept;

  ///
  /// \brief This overloaded dereference operator provides non-const access to
  /// the pointee.
  ///
  /// The overload is chosen when the Ptr object is non-const.
  ///
  [[nodiscard]] constexpr Pointee &operator*() noexcept;

private:
  ///
  /// \brief The underlying pointer that this object wraps.
  ///
  Pointee *mPtr;
};

template <Value Pointee>
[[nodiscard]] constexpr const Pointee *Ptr<Pointee>::operator->() const noexcept {
  return mPtr;
}

template <Value Pointee>
[[nodiscard]] constexpr Pointee *Ptr<Pointee>::operator->() noexcept {
  return mPtr;
}

template <Value Pointee>
[[nodiscard]] constexpr const Pointee &Ptr<Pointee>::operator*() const noexcept {
  return *mPtr;
}

template <Value Pointee> [[nodiscard]] constexpr Pointee &Ptr<Pointee>::operator*() noexcept {
  return *mPtr;
}

template <Value Pointee>
constexpr Ptr<Pointee>::Ptr(Pointee *pOther) noexcept : mPtr(pOther) {}

template <Value Pointee>
constexpr Ptr<Pointee>::Ptr(Ptr<Pointee> &&pOther) noexcept : mPtr(pOther.mPtr) {}

template <Value Pointee>
constexpr Ptr<Pointee> &Ptr<Pointee>::operator=(Ptr<Pointee> &&pOther) &
    noexcept {
  mPtr = pOther.mPtr;
  return *this;
}

} // namespace ezs::adt
