import ezs.tfl.ValueTag;

#include "ezs/test/TEST.hpp"

import ezs.uint_t;

namespace ezs::tfl {

namespace {

struct A {};
struct B {};

template<uint_t idx> auto foo(ValueTag<idx>) {
  if constexpr(idx == 0) {
    return A{};
  } else {
    return B{};
  }
}

// TEST(ezs, tfl, ValueTag, basic) {
//   //////test.assertyyyyyyyyyyyyyyyyyyyyy(true, "a");
// }
} // namespace
}
