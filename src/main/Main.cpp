///
/// \file Main.cpp
/// \brief Module implementation file for Main method.
///
//import ezs;

//import ezs.adt.Value;
#include <iostream>
#include <type_traits>
class A {
 public:
  A() {
    std::cout << std::is_const_v<decltype(this)> << std::endl;
  }
};

int main(void) {
  A a;
  const A b;
}


