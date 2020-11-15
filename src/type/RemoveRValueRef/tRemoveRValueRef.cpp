import ezs.type.RemoveRValueRef;
import ezs.type.SameAs;
using namespace ezs::type;
namespace {

struct Foo {};

static_assert(SameAs<RemoveRValueRef<Foo &&>, Foo>);
static_assert(SameAs<RemoveRValueRef<const Foo &&>, const Foo>);
static_assert(SameAs<RemoveRValueRef<Foo &>, Foo &>);
static_assert(SameAs<RemoveRValueRef<Foo>, Foo>);

} // namespace 
