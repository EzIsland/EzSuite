import ezs.adt.Tuple;
import ezs.test;
import ezs.uint_t;
import ezs.type.forward;
import <string>;
import<cstdio>;
import<optional>;
import <string>;
import<vector>;
import <iostream>;
import<array>;
using namespace ezs::test;

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

Test testGet({"ezs", "adt", "Tuple", "get"}, [](auto& test){
  Tuple<A, B, C> tuple(A{0}, B{1}, C{2});
  test.assert(tuple.get<0>().idA == 0);
  test.assert(tuple.get<1>().idB == 1);
  test.assert(tuple.get<2>().idC == 2);
});

Test testCopy({"ezs", "adt", "Tuple", "copy"}, [](auto &test) {
  Tuple<A, B, C> tuple(A{0}, B{1}, C{2});
  Tuple<A,B,C> copy(tuple);
  test.assert(copy.get<0>().idA == 0);
  test.assert(copy.get<1>().idB == 1);
  test.assert(copy.get<2>().idC == 2);
});

Test testMove({"ezs", "adt", "Tuple", "move"}, [](auto &test) {
  Tuple<A, B, C> tuple(A{0}, B{1}, C{2});
  Tuple<A,B,C> copy(std::move(tuple));
  test.assert(copy.get<0>().idA == 0);
  test.assert(copy.get<1>().idB == 1);
  test.assert(copy.get<2>().idC == 2);
});

Test testCopyAssign({"ezs", "adt", "Tuple", "copyAssign"}, [](auto &test) {
  Tuple<A, B, C> tuple(A{0}, B{1}, C{2});
  Tuple<A,B,C> copy(A{0}, B{0}, C{0});
  copy = tuple;
  test.assert(copy.get<0>().idA == 0);
  test.assert(copy.get<1>().idB == 1);
  test.assert(copy.get<2>().idC == 2);
});



Test testMoveAssign({"ezs", "adt", "Tuple", "moveAssign"}, [](auto& test){
  Tuple<A, B, C> tuple(A{0}, B{1}, C{2});
  Tuple<A,B,C> copy(A{0}, B{0}, C{0});
  copy = std::move(tuple);
  test.assert(copy.get<0>().idA == 0);
  test.assert(copy.get<1>().idB == 1); 
  test.assert(copy.get<2>().idC == 2);
  //const auto& [a, b, c] = copy; 
});
} // namespace 
