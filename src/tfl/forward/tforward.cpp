import ezs.tfl.forward;

import ezs.tfl.ForwardRefOf;

using namespace ezs::tfl;

namespace {

enum class RefType { LValue, RValue };

constexpr RefType getRefType(int &) noexcept { return RefType::LValue; }

constexpr RefType getRefType(int&&) noexcept {
  return RefType::RValue;
}

template<ForwardRefOf<int> T> constexpr RefType foo(T&& pValue) noexcept {
  return getRefType(forward<T>(pValue));
}

static_assert(foo(0) == RefType::RValue);
int a(0);
static_assert(foo(a) == RefType::LValue);

} // namespace
