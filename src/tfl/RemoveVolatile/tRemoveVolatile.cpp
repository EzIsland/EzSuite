import ezs.tfl.RemoveVolatile;
import ezs.tfl.SameAs;

using namespace ezs::tfl;
namespace {

static_assert(SameAs<RemoveVolatile<volatile int>, int>);
static_assert(SameAs<RemoveVolatile<int>, int>);
static_assert(SameAs<RemoveVolatile<const int>, const int>);
static_assert(SameAs<RemoveVolatile<const volatile int>, const int>);
static_assert(SameAs<RemoveVolatile<volatile int *>, volatile int *>);
static_assert(SameAs<RemoveVolatile<volatile int* volatile>, volatile int*>);

} // namespace 
