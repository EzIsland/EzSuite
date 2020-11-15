export module ezs.test.TestPoint;

import ezs.test.TestFailure;
import ezs.test.TestResult;
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
            std::function<void(TestResult&)> pTest)
       : mTest(pTest), mName(pName) {}

  TestResult run() {
    TestResult result;
    
    mTest(result);
    return result;
  }

  TestName getName() const {
    return mName;
  }

 private:
  std::function<void(TestResult&)> mTest;
  TestName mName;
};
} // namespace ezs::test
