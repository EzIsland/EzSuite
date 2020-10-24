///
/// \file Test.hxx
/// \brief Module interface file for ezs::test::Test class.
///
module;

#include <map>
#include <string>
#include <vector>
#include <utility>
#include <functional>

export module ezs.test.Test;

export
namespace ezs::test {

class TestSingleton {
 public:
  static TestSingleton& getInstance() noexcept;

  void registerTest(const std::string&, const std::function<void(void)>&) noexcept;

  void runTests() noexcept;

 private:
  std::map<std::string, std::function<void(void)>> mTests;
};
} // namespace ezs::test

module: private;

namespace ezs::test {
TestSingleton& TestSingleton::getInstance() noexcept {
  static TestSingleton instance;
  return instance;
}

void TestSingleton::registerTest(const std::string& pName, const std::function<void(void)>& pFunction) noexcept {
  mTests.emplace(std::make_pair(pName, pFunction));
}

void TestSingleton::runTests() noexcept {
  for(const auto& [name, function] : mTests) {
    function();
  }
}
}
