export module ezs.uint_t;

import <cstdlib>;

export
namespace ezs {

using uint_t = std::size_t;

constexpr uint_t operator"" _uint(unsigned long long int pLiteral) noexcept {
  return uint_t{pLiteral};
}

} // namespace ezs
