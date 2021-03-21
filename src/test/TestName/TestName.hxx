export module ezs.test.TestName;

import ezs.adt.String;
import <vector>;
import <string>;

export
namespace ezs::test {

class TestName {
 public:  
  TestName(const std::vector<std::string>& pName) : mName(pName) { }

  std::string toString() const {
    std::string result("");
    for(std::size_t idx = 0; idx != mName.size(); ++idx) {
      result += mName[idx];
      if(idx != mName.size() - 1) {
        result += std::string(".");
      }
    }
    return result;
  }
 private:
  std::vector<std::string> mName;
};
}
