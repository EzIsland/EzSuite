export module ezs.test.TestRunner;

import<iostream>;
import<vector>;
import<string>;
import<algorithm>;

import ezs.uint_t;
import ezs.test.TestSingleton;
import ezs.test.TestName;
import ezs.test.TestPoint;
import ezs.test.TestResult;
import ezs.test.TestFailure;
import <filesystem>;
export
namespace ezs::test {


// see https://stackoverflow.com/questions/2896600/how-to-replace-all-occurrences-of-a-character-in-string
std::string replace(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
    }
    return str;
}


class TestRunner final {
 public:
  static int run(const std::vector<std::string>& pTestPoint) {
    bool passing = true;
    uint_t totalAssertions = 0;
    uint_t assertionFailures = 0;
    uint_t totalTests = 0;
    uint_t testFailures = 0;
    auto points = ezs::test::TestSingleton::getInstance().getTestPoints();
    for(TestPoint testPoint : points) {
      if(pTestPoint.size() == 2) {
        auto str = pTestPoint[1];
        auto testPointStr = testPoint.getName().toString();
        if(str.size() > testPointStr.size() ||
           std::mismatch(str.begin(), str.end(), testPointStr.begin(), testPointStr.end()).first != str.end()) {
          continue;
        }
      }
      TestName name = testPoint.getName();
      TestResult result = testPoint.run();

      totalAssertions += result.getTotalAssertions();
      ++totalTests;
      if(result.passed()) {
        std::cout << "\u001b[32m[PASSED]\u001b[30m: ";
        std::cout << name.toString() << "\n";
      } else {
        std::cout << "\n\u001b[31m[FAILED]\u001b[30m: ";
        std::cout << name.toString() << "\n";
        passing = false;
        ++testFailures;
        result.getFailures([&assertionFailures](const auto& failure) {
          ++assertionFailures;
          std::cout << "  \u001b[31m Failure in "
                    << std::filesystem::path(failure.mFile).filename().string() 
                    << ":" << failure.mLine << "\u001b[30m\n";
          if(!failure.mMessage.empty()) {
            auto str = failure.mMessage;
            std::string newStr = replace(str, "\n", "\n     ");
            std::cout << "     " << newStr << "\n";
          }
        });
        std::cout <<  "\n\n";
      }
    }
    std::cout << "\nResults: " << (testFailures ?
                                           "\u001b[31mFAILED\u001b[30m" : "\u001b[32mPASSED\u001b[30m")
              << "\n"
              << "  Failing Tests: " << testFailures 
              << "/" << totalTests << " (" << (static_cast<double>(testFailures)/static_cast<double>(totalTests)*100) << "%)\n";
    
    std::cout << std::endl;
    return static_cast<int>(testFailures);
  }
};
} // namespace 
