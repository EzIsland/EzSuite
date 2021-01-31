import ezs.tfl.RemoveRValueRef;
import ezs.tfl.SameAs;
using namespace ezs::tfl;
namespace {

struct Foo {};

static_assert(SameAs<RemoveRValueRef<Foo &&>, Foo>);
static_assert(SameAs<RemoveRValueRef<const Foo &&>, const Foo>);
static_assert(SameAs<RemoveRValueRef<Foo &>, Foo &>);
static_assert(SameAs<RemoveRValueRef<Foo>, Foo>);

} // namespace 
