export module ezs.adt.RawArrayPtr;

import ezs.uint_t;

export namespace ezs::adt {

template <class Pointee> class RawArrayPtr final {
public:
  RawArrayPtr() = delete;
  RawArrayPtr(const RawArrayPtr<Pointee> &) = delete;
  RawArrayPtr<Pointee> &operator=(const RawArrayPtr<Pointee> &) = delete;

  [[nodiscard]] constexpr RawArrayPtr(Pointee *) noexcept;
  [[nodiscard]] constexpr RawArrayPtr(RawArrayPtr<Pointee> &&) noexcept;
  constexpr RawArrayPtr<Pointee> &operator=(RawArrayPtr<Pointee> &&) & noexcept;

  [[nodiscard]] constexpr Pointee &operator[](uint_t) const noexcept;
  [[nodiscard]] constexpr RawArrayPtr<Pointee> alias() const noexcept;

private:
  Pointee *mPtr;
};

template <class Pointee>
constexpr RawArrayPtr<Pointee>::RawArrayPtr(Pointee *pPtr) noexcept : mPtr(pPtr) {}

template <class Pointee>
constexpr RawArrayPtr<Pointee>::RawArrayPtr(RawArrayPtr<Pointee> &&pOther) noexcept
    : mPtr(pOther.mPtr) {}

template <class Pointee>
    constexpr RawArrayPtr<Pointee> &
    RawArrayPtr<Pointee>::operator=(RawArrayPtr<Pointee> &&pOther) &
    noexcept {
  mPtr = pOther.mPtr;
  return *this;
}

template <class Pointee>
constexpr Pointee &RawArrayPtr<Pointee>::operator[](uint_t pIdx) const noexcept {
  return mPtr[pIdx];
}

template <class Pointee>
constexpr RawArrayPtr<Pointee> RawArrayPtr<Pointee>::alias() const noexcept {
  return RawArrayPtr<Pointee>(mPtr);
}

} // namespace ezs::adt
