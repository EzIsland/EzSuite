import ezs.adt.Tuple;

#include "ezs/test/TEST.hpp"

import ezs.uint_t;
import ezs.tfl.forward;


namespace ezs::adt {
struct A {
  uint_t idA;
};

struct B {
  uint_t idB;
};

struct C {
  uint_t idC;
};

TEST(ezs, adt, Tuple, get) {
  Tuple<A, B, C> tuple(A{0}, B{1}, C{2});
  test.assert(tuple.get<0>().idA == 0);
  test.assert(tuple.get<1>().idB == 1);
  test.assert(tuple.get<2>().idC == 2);
}

TEST(ezs, adt, Tuple, copy) {
  Tuple<A, B, C> tuple(A{0}, B{1}, C{2});
  Tuple<A,B,C> copy(tuple);
  test.assert(copy.get<0>().idA == 0);
  test.assert(copy.get<1>().idB == 1);
  test.assert(copy.get<2>().idC == 2);
}

TEST(ezs, adt, Tuple, move) {
  Tuple<A, B, C> tuple(A{0}, B{1}, C{2});
  Tuple<A,B,C> copy(std::move(tuple));
  test.assert(copy.get<0>().idA == 0);
  test.assert(copy.get<1>().idB == 1);
  test.assert(copy.get<2>().idC == 2);
}

TEST(ezs, adt, Tuple, assign) {
  Tuple<A, B, C> tuple(A{0}, B{1}, C{2});
  Tuple<A,B,C> copy(A{0}, B{0}, C{0});
  copy = tuple;
  test.assert(copy.get<0>().idA == 0);
  test.assert(copy.get<1>().idB == 1);
  test.assert(copy.get<2>().idC == 2);
}

TEST(ezs, adt, Tuple, assignMove) {
  Tuple<A, B, C> tuple(A{0}, B{1}, C{2});
  Tuple<A,B,C> copy(A{0}, B{0}, C{0});
  copy = std::move(tuple);
  test.assert(copy.get<0>().idA == 0);
  test.assert(copy.get<1>().idB == 1); 
  test.assert(copy.get<2>().idC == 2);
  //const auto& [a, b, c] = copy; 
}
} // namespace 
