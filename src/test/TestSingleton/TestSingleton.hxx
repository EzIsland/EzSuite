export module ezs.test.TestSingleton;

import ezs.test.TestPoint;
import ezs.test.TestName;
import ezs.test.TestResult;

import <vector>;

export
namespace ezs::test {

class TestSingleton final {
 public:
  TestSingleton(const TestSingleton&) = delete;
  TestSingleton(TestSingleton&&) = delete;
  TestSingleton& operator=(const TestSingleton&) = delete;
  TestSingleton& operator=(TestSingleton&&) = delete;
  
  static TestSingleton& getInstance() noexcept;

  void registerTest(const TestPoint&) noexcept;

  std::vector<TestPoint> getTestPoints() {
    return mTests;
  }

 private:
  std::vector<TestPoint> mTests;

  TestSingleton() noexcept = default;
};

} // namespace ezs::test
