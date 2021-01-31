import ezs.tfl.RemoveLValueRef;
import ezs.tfl.SameAs;
using namespace ezs::tfl;
namespace {

struct Foo {};
static_assert(SameAs<RemoveLValueRef<Foo &>, Foo>);
static_assert(SameAs<RemoveLValueRef<const Foo &>, const Foo>);
static_assert(SameAs<RemoveLValueRef<Foo &&>, Foo &&>);
static_assert(SameAs<RemoveLValueRef<Foo>, Foo>);

} // namespace 
