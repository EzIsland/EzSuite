import ezs.type.RemoveLValueRef;
import ezs.type.SameAs;
using namespace ezs::type;
namespace {

struct Foo {};
static_assert(SameAs<RemoveLValueRef<Foo &>, Foo>);
static_assert(SameAs<RemoveLValueRef<const Foo &>, const Foo>);
static_assert(SameAs<RemoveLValueRef<Foo &&>, Foo &&>);
static_assert(SameAs<RemoveLValueRef<Foo>, Foo>);

} // namespace 
