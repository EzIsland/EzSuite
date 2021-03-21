import ezs.adt.Variant;
import ezs.tfl.ValueTag;
import ezs.uint_t;
import ezs.tfl.forward;
import ezs.cfl.assert;
import ezs.tfl;

#include "ezs/test/TEST.hpp"


namespace ezs::adt {

namespace {



//static_assert(tfl::SameAs<decltype(tfl::declval<Variant<A, B, C>&>().get<0>()), A&>);


// struct A {
//   uint_t mValue;
// };

// struct B {
//   uint_t mValue;
// };

// struct C {
//   uint_t mValue;
// };

// TEST(ezs, adt, Variant, basic) {
//   Variant<A, B, C> variant{tfl::ValueTag<0_uint>{}, 0_uint};
//   A a = variant.get<0>();
  
//   variant.emplace<1>(0_uint);
//   B b = variant.get<1>();
  
//   variant.emplace<2>(0_uint);
//   C c = variant.get<2>();
  
//   //////test.assert(a.mValue == 0_uint);
//   //////test.assert(b.mValue == 0_uint);
//   //////test.assert(c.mValue == 0_uint);
// }

// TEST(ezs, adt, Variant, basic) {
//   Variant<A, B, C> variant{tfl::ValueTag<1_uint>{}, 0_uint};
//   B a = variant.get<1_uint>();
//   //////test.assert(a.mValue == 0_uint);
// }

} // namespace 
} // namespace ezs::adt
