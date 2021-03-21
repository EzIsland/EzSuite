import ezs.adt.Vector;

import ezs.uint_t;
import ezs.cfl.SourceLocation;
import ezs.adt.String;
import ezs.test.Tester;
import ezs.adt.ForwardingTuple;
import ezs.tfl.forward;
import ezs.tfl.move;
import<compare>;

#include "ezs/test/TEST.hpp"

namespace ezs::adt {
namespace {

struct Foo {
  uint_t mX;
  uint_t mY;
  std::strong_ordering operator<=>(const Foo&) const = default;
};

template<typename T>
class VectorTester {
 public:
  Vector<T> mVector;
  
  void verifyElement(
      uint_t pIdx,
      const T& pElement,
      const cfl::SourceLocation& pLocation = cfl::SourceLocation::current());
  void verifySizeEquals(
      uint_t pExpectedSize,
      const cfl::SourceLocation& pLocation = cfl::SourceLocation::current());
  void verifySizeGreaterThan(
      uint_t pValue,
      const cfl::SourceLocation& pLocation = cfl::SourceLocation::current());

  VectorTester(test::Tester& mTester);

 private:
  test::Tester& mTester;
};

adt::String toString(uint_t pValue) {
  return std::to_string(pValue);
}

adt::String toString(Foo pValue) {
  return "Foo{"+toString(pValue.mX)+", "+toString(pValue.mY)+"}";
}

adt::String makeVerifySizeEqualsDiagnostic(uint_t pExpectedSize, uint_t pActualSize) {
  return adt::String{
      "Expected: mVector.size() == " + toString(pExpectedSize) + "\n" +
      "Actual:   mVector.size() == " + toString(pActualSize)};
}

adt::String makeVerifySizeGreaterThanDiagnostic(uint_t pValue, uint_t pActualSize) {
  return adt::String{
    "Expected: mVector.size() >  " + toString(pValue) + "\n" +
    "Actual:   mVector.size() == " + toString(pActualSize)};
}

template<typename T>
adt::String makeVerifyElementDiagnostic(
    uint_t pIdx, const T& pExpectedElement, const T& pActualElement) {
  return adt::String{
    "Expected: mVector["+toString(pIdx)+"] == " + toString(pExpectedElement) + "\n" +
    "Actual:   mVector["+toString(pIdx)+"] == " + toString(pActualElement)};
}

template<typename T>
void VectorTester<T>::verifyElement(
    uint_t pIdx,
    const T& pExpectedElement,
    const cfl::SourceLocation& pLocation) {
  verifySizeGreaterThan(pIdx, pLocation);
  T actualElement = mVector[pIdx];
  if(actualElement != pExpectedElement) {
    mTester.fail(makeVerifyElementDiagnostic(pIdx, pExpectedElement, actualElement), pLocation);
  }
}

template<typename T>
void VectorTester<T>::verifySizeEquals(
    uint_t pExpectedSize,
    const cfl::SourceLocation& pLocation) {
  uint_t actualSize = mVector.size();
  if(pExpectedSize != actualSize) {
    mTester.fail(makeVerifySizeEqualsDiagnostic(pExpectedSize, actualSize),
                 pLocation);
  }
}

template <typename T>
void VectorTester<T>::verifySizeGreaterThan(
    uint_t pValue,
    const cfl::SourceLocation& pLocation) {
  uint_t actualSize = mVector.size();
  if(actualSize <= pValue) {
    mTester.fail(makeVerifySizeGreaterThanDiagnostic(pValue, actualSize), pLocation);
  }
}

template <typename T>
VectorTester<T>::VectorTester(test::Tester& pTester) : mTester(pTester) { }

/////////////////////////////////////////////////////////////////////////////

TEST(ezs, adt, Vector, constructEmptyVector) {
  VectorTester<uint_t> tester(pTester);
  tester.mVector = Vector<uint_t>{};
  tester.verifySizeEquals(0_uint);
}

TEST(ezs, adt, Vector, constructFilledVector) {
  VectorTester<uint_t> tester(pTester);
  tester.mVector = Vector<uint_t>{0_uint, 1_uint, 2_uint};
  tester.verifyElement(0_uint, 0_uint);
  tester.verifyElement(1_uint, 1_uint);
  tester.verifyElement(2_uint, 2_uint);
  tester.verifySizeEquals(3_uint);
}

TEST(ezs, adt, Vector, emplaceBackElementsToEmptyVector) {
  VectorTester<uint_t> tester(pTester);
  tester.mVector = Vector<uint_t>{};
  tester.verifySizeEquals(0_uint);
  
  tester.mVector.emplaceBack(0_uint);
  tester.verifyElement(0_uint, 0_uint);
  tester.verifySizeEquals(1_uint);
  
  tester.mVector.emplaceBack(1_uint);
  tester.verifyElement(0_uint, 0_uint);
  tester.verifyElement(1_uint, 1_uint);
  tester.verifySizeEquals(2_uint);
  
  tester.mVector.emplaceBack(2_uint);
  tester.verifyElement(0_uint, 0_uint);
  tester.verifyElement(1_uint, 1_uint);
  tester.verifyElement(2_uint, 2_uint);
  tester.verifySizeEquals(3_uint);
}

TEST(ezs, adt, Vector, emplaceBackElementsToFilledVector) {
  VectorTester<uint_t> tester(pTester);
  tester.mVector = Vector<uint_t>{0_uint, 1_uint, 2_uint};
  tester.verifyElement(0_uint, 0_uint);
  tester.verifyElement(1_uint, 1_uint);
  tester.verifyElement(2_uint, 2_uint);
  tester.verifySizeEquals(3_uint);
  
  tester.mVector.emplaceBack(0_uint);
  tester.verifyElement(0_uint, 0_uint);
  tester.verifyElement(1_uint, 1_uint);
  tester.verifyElement(2_uint, 2_uint);
  tester.verifyElement(3_uint, 3_uint);
  tester.verifySizeEquals(4_uint);
  
  tester.mVector.emplaceBack(1_uint);
  tester.verifyElement(0_uint, 0_uint);
  tester.verifyElement(1_uint, 1_uint);
  tester.verifyElement(2_uint, 2_uint);
  tester.verifyElement(3_uint, 3_uint);
  tester.verifyElement(4_uint, 4_uint);
  tester.verifySizeEquals(5_uint);
}

TEST(ezs, adt, Vector, constructAndModifyVector) {
  VectorTester<uint_t> tester(pTester);
  tester.mVector = Vector<uint_t>{0_uint, 1_uint, 2_uint};
  tester.verifySizeEquals(3_uint);
  tester.verifyElement(0_uint, 0_uint);
  tester.verifyElement(1_uint, 1_uint);
  tester.verifyElement(2_uint, 2_uint);

  tester.mVector[1] = 100_uint;
  tester.verifySizeEquals(3_uint);
  tester.verifyElement(0_uint, 0_uint);
  tester.verifyElement(1_uint, 100_uint);
  tester.verifyElement(2_uint, 2_uint);

  tester.mVector[0] = 300_uint;
  tester.verifySizeEquals(3_uint);
  tester.verifyElement(0_uint, 300_uint);
  tester.verifyElement(1_uint, 100_uint);
  tester.verifyElement(2_uint, 2_uint);

  tester.mVector[2] = 400_uint;
  tester.verifySizeEquals(3_uint);
  tester.verifyElement(0_uint, 300_uint);
  tester.verifyElement(1_uint, 100_uint);
  tester.verifyElement(2_uint, 400_uint);

  tester.mVector[1] = 1_uint;
  tester.verifySizeEquals(3_uint);
  tester.verifyElement(0_uint, 300_uint);
  tester.verifyElement(1_uint, 1_uint);
  tester.verifyElement(2_uint, 400_uint);
}

TEST(ezs, adt, Vector, constructEmptyFooVector) {
  VectorTester<Foo> tester(pTester);
  tester.mVector = Vector<Foo>{};
  tester.verifySizeEquals(0_uint);
}

TEST(ezs, adt, Vector, constructFooVectorByCopy) {
  VectorTester<Foo> tester(pTester);
  tester.mVector = Vector<Foo>{Foo{0_uint, 0_uint}, Foo{1_uint, 1_uint}, Foo{2_uint, 2_uint}};
  tester.verifySizeEquals(3_uint);
  tester.verifyElement(0, Foo{0_uint, 0_uint});
  tester.verifyElement(1, Foo{1_uint, 1_uint});
  tester.verifyElement(2, Foo{2_uint, 2_uint});
}

TEST(ezs, adt, Vector, constructFooVectorByForwardingTuple) {
  VectorTester<Foo> tester(pTester);
  uint_t x{0};
  uint_t y{1};
  uint_t z{2};
  tester.mVector = Vector<Foo>{
    adt::forwardAsTuple(x, 0_uint),
    adt::forwardAsTuple(1_uint, y),
    adt::forwardAsTuple(tfl::move(z), 2_uint)};
  tester.verifySizeEquals(3_uint);
  tester.verifyElement(0, Foo{0_uint, 0_uint});
  tester.verifyElement(1, Foo{1_uint, 1_uint});
  tester.verifyElement(2, Foo{2_uint, 2_uint});
}

TEST(ezs, adt, Vector, emplaceBackFooByValue) {
  VectorTester<Foo> tester(pTester);
  tester.mVector = Vector<Foo>{};
  tester.verifySizeEquals(0_uint);

  Foo foo0{0_uint, 0_uint};
  tester.mVector.emplaceBack(foo0);
  tester.verifySizeEquals(1_uint);
  tester.verifyElement(0, Foo{0_uint, 0_uint});
  
  Foo foo1{1_uint, 1_uint};
  tester.mVector.emplaceBack(foo1);
  tester.verifySizeEquals(2_uint);
  tester.verifyElement(0, Foo{0_uint, 0_uint});
  tester.verifyElement(1, Foo{1_uint, 1_uint});

  Foo foo2{2_uint, 2_uint};
  tester.mVector.emplaceBack(foo2);
  tester.verifySizeEquals(3_uint);
  tester.verifyElement(0, Foo{0_uint, 0_uint});
  tester.verifyElement(1, Foo{1_uint, 1_uint});
  tester.verifyElement(2, Foo{2_uint, 2_uint});
}

TEST(ezs, adt, Vector, emplaceBackFooByMove) {
  VectorTester<Foo> tester(pTester);
  tester.mVector = Vector<Foo>{};
  tester.verifySizeEquals(0_uint);

  Foo foo0{0_uint, 0_uint};
  tester.mVector.emplaceBack(tfl::move(foo0));
  tester.verifySizeEquals(1_uint);
  tester.verifyElement(0, Foo{0_uint, 0_uint});
  
  tester.mVector.emplaceBack(Foo{1_uint, 1_uint});
  tester.verifySizeEquals(2_uint);
  tester.verifyElement(0, Foo{0_uint, 0_uint});
  tester.verifyElement(1, Foo{1_uint, 1_uint});

  Foo foo2{2_uint, 2_uint};
  tester.mVector.emplaceBack(tfl::move(foo2));
  tester.verifySizeEquals(3_uint);
  tester.verifyElement(0, Foo{0_uint, 0_uint});
  tester.verifyElement(1, Foo{1_uint, 1_uint});
  tester.verifyElement(2, Foo{2_uint, 2_uint});
}

TEST(ezs, adt, Vector, emplaceBackFooByArgument) {
  VectorTester<Foo> tester(pTester);
  tester.mVector = Vector<Foo>{};
  tester.verifySizeEquals(0_uint);

  tester.mVector.emplaceBack(0_uint, 0_uint);
  tester.verifySizeEquals(1_uint);
  tester.verifyElement(0, Foo{0_uint, 0_uint});
  
  tester.mVector.emplaceBack(1_uint, 1_uint);
  tester.verifySizeEquals(2_uint);
  tester.verifyElement(0, Foo{0_uint, 0_uint});
  tester.verifyElement(1, Foo{1_uint, 1_uint});

  tester.mVector.emplaceBack(2_uint, 2_uint);
  tester.verifySizeEquals(3_uint);
  tester.verifyElement(0, Foo{0_uint, 0_uint});
  tester.verifyElement(1, Foo{1_uint, 1_uint});
  tester.verifyElement(2, Foo{2_uint, 2_uint});
}

TEST(ezs, adt, Vector, copyAssignFooVector) {
  VectorTester<Foo> tester(pTester);
  Vector<Foo> fooVector{
    Foo{0_uint, 0_uint},
    Foo{1_uint, 1_uint},
    Foo{2_uint, 2_uint}};
  tester.mVector = fooVector;
  tester.verifySizeEquals(3_uint);
  tester.verifyElement(0, Foo{0_uint, 0_uint});
  tester.verifyElement(1, Foo{1_uint, 1_uint});
  tester.verifyElement(2, Foo{2_uint, 2_uint});
}

TEST(ezs, adt, Vector, moveAssignFooVector) {
  VectorTester<Foo> tester(pTester);
  Vector<Foo> fooVector{
    Foo{0_uint, 0_uint},
    Foo{1_uint, 1_uint},
    Foo{2_uint, 2_uint}};
  tester.mVector = tfl::move(fooVector);
  tester.verifySizeEquals(3_uint);
  tester.verifyElement(0, Foo{0_uint, 0_uint});
  tester.verifyElement(1, Foo{1_uint, 1_uint});
  tester.verifyElement(2, Foo{2_uint, 2_uint});
}

TEST(ezs, adt, Vector, copyConstructFooVector) {
  VectorTester<Foo> tester(pTester);
  Vector<Foo> fooVector{
    Foo{0_uint, 0_uint},
    Foo{1_uint, 1_uint},
    Foo{2_uint, 2_uint}};
  Vector<Foo> copy{fooVector};
  tester.mVector = copy;
  tester.verifySizeEquals(3_uint);
  tester.verifyElement(0, Foo{0_uint, 0_uint});
  tester.verifyElement(1, Foo{1_uint, 1_uint});
  tester.verifyElement(2, Foo{2_uint, 2_uint});
}

TEST(ezs, adt, Vector, moveConstructFooVector) {
  VectorTester<Foo> tester(pTester);
  Vector<Foo> fooVector{
    Foo{0_uint, 0_uint},
    Foo{1_uint, 1_uint},
    Foo{2_uint, 2_uint}};
  Vector<Foo> copy{tfl::move(fooVector)};
  tester.mVector = copy;
  tester.verifySizeEquals(3_uint);
  tester.verifyElement(0, Foo{0_uint, 0_uint});
  tester.verifyElement(1, Foo{1_uint, 1_uint});
  tester.verifyElement(2, Foo{2_uint, 2_uint});
}

TEST(ezs, adt, Vector, constructAndModifyFooVector) {
  VectorTester<Foo> tester(pTester);
  tester.mVector = Vector<Foo>{
    Foo{0_uint, 0_uint},
    Foo{1_uint, 1_uint},
    Foo{2_uint, 2_uint}};
  tester.verifySizeEquals(3_uint);
  tester.verifyElement(0, Foo{0_uint, 0_uint});
  tester.verifyElement(1, Foo{1_uint, 1_uint});
  tester.verifyElement(2, Foo{2_uint, 2_uint});

  tester.mVector[0_uint].mX = 200_uint;
  tester.mVector[0_uint].mX = 300_uint;
  tester.mVector[1_uint] = Foo{400_uint, 500_uint};
  tester.mVector[2_uint].mY = 600_uint;
  
  tester.verifySizeEquals(3_uint);
  tester.verifyElement(0, Foo{200_uint, 300_uint});
  tester.verifyElement(1, Foo{400_uint, 500_uint});
  tester.verifyElement(2, Foo{2_uint, 600_uint});
}

} // namespace
} // namespace ezs::adt
