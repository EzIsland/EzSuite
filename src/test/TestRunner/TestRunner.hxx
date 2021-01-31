export module ezs.test.TestRunner;

import<iostream>;
import<vector>;
import<string>;

import ezs.uint_t;
import ezs.test.TestSingleton;
import ezs.test.TestName;
import ezs.test.TestPoint;
import ezs.test.TestResult;
import ezs.test.TestFailure;
import <filesystem>;
export
namespace ezs::test {

class TestRunner final {
 public:
  static int run(const std::vector<std::string>&) {
    bool passing = true;
    uint_t totalAssertions = 0;
    uint_t assertionFailures = 0;
    uint_t totalTests = 0;
    uint_t testFailures = 0;
    auto points = ezs::test::TestSingleton::getInstance().getTestPoints();
    for(TestPoint testPoint : points) {
      TestName name = testPoint.getName();
      TestResult result = testPoint.run();
      std::cout << name.toString() << ": ";
      totalAssertions += result.getTotalAssertions();
      ++totalTests;
      if(result.passed()) {
        std::cout << "PASSED";
      } else {
        std::cout << "FAILED\n";
        passing = false;
        ++testFailures;
        result.getFailures([&assertionFailures](const auto& failure) {
          ++assertionFailures;
          std::cout << "  Failure in "
                    << std::filesystem::path(failure.mFile).filename().string() 
                    << ":" << failure.mLine << " " << failure.mMessage << "\n";
        });
      }
      std::cout << "\n";
      std::cout << std::endl;
    }
    std::cout << "\nOverall results: " << (testFailures ? "FAILED" : "PASSED")
              << "\n"
              << "  Failing Tests: " << testFailures << "\n"
              << "  Passing Tests: " << totalTests - testFailures << "\n"
              << "  Total Tests: " << totalTests << "\n"
              << "  Failing Assertions: " << assertionFailures << "\n"
              << "  Passing Assertions: " << totalAssertions - assertionFailures << "\n"
              << "  Total Assertions: " << totalAssertions << "\n";
    
    std::cout << std::endl;
    return static_cast<int>(testFailures);
  }
};
} // namespace 
