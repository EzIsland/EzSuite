export module ezs.test.TestFailure;
import ezs.uint_t;

import <string>;
export
namespace ezs::test {
struct TestFailure final {
  uint_t mLine;
  std::string mFile;
  std::string mMessage;
};
} // namespace 
