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
    for(const std::string& name : mName) {
      result += name + std::string(".");
    }
    return result;
  }
 private:
  std::vector<std::string> mName;
};
}
