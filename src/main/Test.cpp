import ezs.test.TestSingleton;
import ezs.test.TestName;
import ezs.test.TestResult;
import ezs.test.TestRunner;
import <iostream>;
import <vector>;
import <string>;

int main(int argc, const char** argv) {
  std::vector<std::string> args;
  for(int i = 0; i != argc; ++i) {
    args.emplace_back(argv[i]);
  }
  return ezs::test::TestRunner::run(args);
}
