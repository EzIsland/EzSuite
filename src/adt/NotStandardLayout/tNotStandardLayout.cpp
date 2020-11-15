import ezs.adt.NotStandardLayout;
import<type_traits>; 

#include "NOT_STANDARD_LAYOUT.hpp"
using namespace ezs::adt;
namespace {
static_assert(sizeof(NotStandardLayout<int>) == 1);
static_assert(!std::is_standard_layout_v<NotStandardLayout<int>>);
static_assert(std::is_trivial_v<NotStandardLayout<int>>);

class Foo { 
 private:
  NOT_STANDARD_LAYOUT(Foo);
};

static_assert(!std::is_standard_layout_v<Foo>);
static_assert(sizeof(Foo) == 1);
static_assert(alignof(Foo) == 1); 

static_assert(alignof(NotStandardLayout<int>) == 1);
} // namespace 
