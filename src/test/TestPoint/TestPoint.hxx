export module ezs.test.TestPoint;

import ezs.test.TestFailure;
import ezs.test.TestResult;
import ezs.test.Tester;
import ezs.test.TestName;
import ezs.uint_t;

import <string>;
import <optional>;
import <functional>;
import <vector>;
import <iostream>;
export namespace ezs::test {

class TestPoint final {
 public:
  TestPoint(const std::vector<std::string>& pName,
            std::function<void(Tester&)> pTest)
       : mTest(pTest), mName(pName) {}

  TestResult run() {
    Tester tester;
    
    mTest(tester);
    return tester.getResult();
  }

  TestName getName() const {
    return mName;
  }

 private:
  std::function<void(Tester&)> mTest;
  TestName mName;
};
} // namespace ezs::test
