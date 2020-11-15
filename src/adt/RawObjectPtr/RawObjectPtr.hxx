export module ezs.adt.RawObjectPtr;

export namespace ezs::adt {

template <typename Pointee> class RawObjectPtr final {
public:
  RawObjectPtr() = delete;
  RawObjectPtr(const RawObjectPtr<Pointee> &) = delete;
  RawObjectPtr<Pointee> &operator=(const RawObjectPtr<Pointee> &) = delete;
  
  [[nodiscard]] explicit constexpr RawObjectPtr(Pointee *) noexcept;
  [[nodiscard]] constexpr RawObjectPtr(RawObjectPtr<Pointee> &&) noexcept;
  constexpr RawObjectPtr<Pointee> &operator=(RawObjectPtr<Pointee> &&) & noexcept;

  [[nodiscard]] constexpr Pointee &operator*() const noexcept;
  [[nodiscard]] constexpr Pointee *operator->() const noexcept;
  [[nodiscard]] constexpr RawObjectPtr<Pointee> alias() const noexcept;

private:
  Pointee *mPtr;
};

template <typename Pointee>
constexpr RawObjectPtr<Pointee>::RawObjectPtr(Pointee *pPtr) noexcept : mPtr(pPtr) {}

template <typename Pointee>
constexpr RawObjectPtr<Pointee>::RawObjectPtr(RawObjectPtr<Pointee> &&pOther) noexcept
    : mPtr(pOther.mPtr) {}

template <typename Pointee>
    constexpr RawObjectPtr<Pointee> &
    RawObjectPtr<Pointee>::operator=(RawObjectPtr<Pointee> &&pOther) &
    noexcept {
  mPtr = pOther.mPtr;
  return *this;
}

template <typename Pointee>
constexpr Pointee &RawObjectPtr<Pointee>::operator*() const noexcept {
  return *mPtr;
}

template <typename Pointee>
constexpr Pointee *RawObjectPtr<Pointee>::operator->() const noexcept {
  return mPtr;
}

template <typename Pointee>
constexpr RawObjectPtr<Pointee> RawObjectPtr<Pointee>::alias() const noexcept {
  return RawObjectPtr<Pointee>(mPtr);
}

} // namespace ezs::adt

