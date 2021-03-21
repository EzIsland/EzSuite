export module ezs.test.TestResult;

import ezs.uint_t;
import ezs.adt.String;
import ezs.cfl.SourceLocation;
import ezs.test.TestFailure;
import <string>;
import <vector>;
import <source_location>;
import <cstdlib>;
import <tuple>;
export
namespace ezs::test {

class TestResult final {
 public:

  TestResult() : mFailures(), mTotalAssertions(0) { }

  // void assert(bool pValue,
  //             const std::string& pMessage = "",
  //             const std::source_location& pLocation = std::source_location::current()) {
  //   ++mTotalAssertions;
  //   if(!pValue) {
  //     mFailures.push_back({pLocation.line(),
  //                            pLocation.file_name(),
  //                            pMessage});
  //   }
  // }

  void addFailure(const adt::String& pMessage, const cfl::SourceLocation& pLocation) {
    ++mTotalAssertions;
    mFailures.push_back({pLocation.getLine(), pLocation.getFileName(), pMessage});
  }

  bool passed() const {
    return mFailures.empty();
  }

  template<typename Func> void getFailures(const Func& func) const {
    for(const auto& failure : mFailures) {
      func(failure);
    }
  }

  uint_t getTotalAssertions()const {
    return mTotalAssertions;
  }

 private:
  std::vector<TestFailure> mFailures;
  uint_t mTotalAssertions;
};
} // namespace ezs::test

