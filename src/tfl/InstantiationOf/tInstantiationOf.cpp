import ezs.tfl.InstantiationOf;

#include "ezs/test/TEST.hpp"

namespace ezs::tfl {

namespace { 

template <typename T> struct Foo {};
template <typename T> struct Bar {};

static_assert(InstantiationOf<Foo<int>, Foo>);
static_assert(InstantiationOf<Foo<double>, Foo>);
static_assert(InstantiationOf<Foo<char>, Foo>);
static_assert(!InstantiationOf<Foo<char>, Bar>);

// TEST(ezs, tfl, InstantiationOf, basic) {
//   //////test.assert(true);
// }
} // namespace
} // namespace ezs::tfl
