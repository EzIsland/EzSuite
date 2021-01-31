import ezs.tfl.SameAs;

using namespace ezs::tfl; 

namespace {

static_assert(SameAs<int, int>);

struct Foo { };
static_assert(SameAs<Foo, Foo>);

static_assert(!SameAs<int, int &>);
static_assert(!SameAs<int, int &&>);
static_assert(!SameAs<int&, int &&>);
static_assert(!SameAs<const int, int>);
static_assert(!SameAs<volatile int, int>);
static_assert(!SameAs<int*, const int*>);

} // namespace 
