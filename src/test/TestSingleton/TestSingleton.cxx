module ezs.test.TestSingleton;

import ezs.test.TestPoint;
import ezs.test.TestName;

import <string>;
import <optional>;
import <vector>;

namespace ezs::test {

TestSingleton& TestSingleton::getInstance() noexcept { 
  static TestSingleton instance;
  return instance;
}

void TestSingleton::registerTest(const TestPoint& pTest) noexcept {
  mTests.emplace_back(pTest);
}
}
