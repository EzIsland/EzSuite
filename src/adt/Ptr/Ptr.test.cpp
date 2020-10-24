#include <string>
#include <cstdio>

import ezs.test.Test;
import ezs.adt.Ptr;



namespace {
void myfun() {
  printf("Hello, World\n");
}

void myfun2() {
  printf("Hello, World2\n");
}


class PtrTest {
 public:
  PtrTest();
};
PtrTest::PtrTest() {
  ezs::test::TestSingleton::getInstance().registerTest(std::string("A"), &myfun);
  ezs::test::TestSingleton::getInstance().registerTest(std::string("B"), &myfun2);
}

PtrTest test;
}
