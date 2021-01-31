import ezs.tfl.RemoveRef;
import ezs.tfl.SameAs;
using namespace ezs::tfl;
namespace {
struct Foo { };
static_assert(SameAs<RemoveRef<Foo &>, Foo>);
static_assert(SameAs<RemoveRef<Foo&&>, Foo>);
static_assert(SameAs<RemoveRef<Foo>, Foo>);
static_assert(SameAs<RemoveRef<const Foo>, const Foo>);
static_assert(SameAs<RemoveRef<const Foo &>, const Foo>);
static_assert(SameAs<RemoveRef<const Foo&&>, const Foo>);
} // namespace 
