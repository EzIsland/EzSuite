///
/// \file Test.hxx
/// \brief Module interface file for ezs::test::Test class.
///
export module ezs.test.Test;

import ezs.test.TestSingleton;
import ezs.test.TestPoint;
import ezs.test.TestName;
import ezs.test.TestResult;
import ezs.uint_t;
import <vector>;

import<string>;
import <optional>;

export
namespace ezs::test {


class Test {
 public:
  Test() = delete;
  Test(const Test&) = delete;
  Test(Test&&) = delete;
  void operator=(const Test&) = delete;
  void operator=(Test&&) = delete;
  
  Test(const std::vector<std::string>& pName, std::function<void(TestResult&)> pFunction) {
    TestSingleton::getInstance().registerTest(TestPoint(pName, pFunction));
}
};


} // namespace ezs::test

