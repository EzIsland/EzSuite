module;

#include "boost/stacktrace.hpp"
#undef assert

module ezs.cfl.assert;

import<iostream>;
import<source_location>;

namespace ezs::cfl {
void assert(bool pAssert, const std::source_location& pLocation) {
  if(!pAssert) {
    std::cout << "Assertion in " << pLocation.function_name()
              << " at " << pLocation.file_name()
              << ":" << pLocation.line() << ":" << pLocation.column()
              << " failed.\n\nStack Trace:\n"
              << boost::stacktrace::stacktrace() << std::endl;
    std::terminate();
  }
}

void assert(bool pAssert, const std::string& pMessage, const std::source_location& pLocation) {
  if(!pAssert) {
    std::cout << "Assertion failed with message\n\n  "
              << pMessage << "\n\n"
              << "In " << pLocation.function_name()
              << " at " << pLocation.file_name()
              << ":" << pLocation.line() << ":" << pLocation.column()
              <<"\n\nStack Trace:\n"
              << boost::stacktrace::stacktrace() << std::endl;
    std::terminate();
  }
}

void assert(bool pAssert, const char* const pMessage, const std::source_location& pLocation) {
  assert(pAssert, std::string(pMessage), pLocation);
}
} // namespace ezs::cfl
