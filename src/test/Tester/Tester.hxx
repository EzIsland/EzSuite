export module ezs.test.Tester;

import ezs.test.TestResult;
import ezs.adt.String;
import ezs.cfl.SourceLocation;
import ezs.test.TestFailure;
import<vector>;
import<string>;

export
namespace ezs::test {

       

class Tester final {
 private:
  TestResult mResult;

 public:
  TestResult getResult() const {
    return mResult;
  }

  void fail(const adt::String& pMessage, const cfl::SourceLocation& pLocation) {
    mResult.addFailure(pMessage, pLocation);
  }
};

} // namespace ezs::test
