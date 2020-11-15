import ezs.type.Ref;
using namespace ezs::type;
namespace {

struct Foo { };
static_assert(Ref<Foo &>);
static_assert(Ref<Foo &&>);
static_assert(!Ref<Foo>);

} // namespace 
