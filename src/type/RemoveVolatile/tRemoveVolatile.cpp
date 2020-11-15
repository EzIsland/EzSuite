import ezs.type.RemoveVolatile;
import ezs.type.SameAs;

using namespace ezs::type;
namespace {

static_assert(SameAs<RemoveVolatile<volatile int>, int>);
static_assert(SameAs<RemoveVolatile<int>, int>);
static_assert(SameAs<RemoveVolatile<const int>, const int>);
static_assert(SameAs<RemoveVolatile<const volatile int>, const int>);
static_assert(SameAs<RemoveVolatile<volatile int *>, volatile int *>);
static_assert(SameAs<RemoveVolatile<volatile int* volatile>, volatile int*>);

} // namespace 
