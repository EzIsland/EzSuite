import ezs.type.RemoveConst;
import ezs.type.SameAs;

using namespace ezs::type;
namespace {

struct Foo { };

static_assert(SameAs<RemoveConst<const int>, int>);
static_assert(SameAs<RemoveConst<int>, int>);
static_assert(SameAs<RemoveConst<volatile int>, volatile int>);
static_assert(SameAs<RemoveConst<const volatile int>, volatile int>);
static_assert(SameAs<RemoveConst<int &>, int &>);
static_assert(SameAs<RemoveConst<const int &>, const int &>);
static_assert(SameAs<RemoveConst<const int *>, const int *>);
static_assert(SameAs<RemoveConst<const int * const>, const int *>);
static_assert(SameAs<RemoveConst<const int[]>, int[]>);
static_assert(SameAs<RemoveConst<int[]>, int[]>);
static_assert(SameAs<RemoveConst<const Foo>, Foo>);
static_assert(SameAs<RemoveConst<Foo>, Foo>);

} // namespace 
