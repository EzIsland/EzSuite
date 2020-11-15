module ezs.test.Test;

import ezs.test.TestSingleton;

namespace ezs::test {
int f() {
  TestSingleton::getInstance();
  return 0;
}  
}
