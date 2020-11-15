import ezs.type.RemoveRef;
import ezs.type.SameAs;
using namespace ezs::type;
namespace {
struct Foo { };
static_assert(SameAs<RemoveRef<Foo &>, Foo>);
static_assert(SameAs<RemoveRef<Foo&&>, Foo>);
static_assert(SameAs<RemoveRef<Foo>, Foo>);
static_assert(SameAs<RemoveRef<const Foo>, const Foo>);
static_assert(SameAs<RemoveRef<const Foo &>, const Foo>);
static_assert(SameAs<RemoveRef<const Foo&&>, const Foo>);
} // namespace 
