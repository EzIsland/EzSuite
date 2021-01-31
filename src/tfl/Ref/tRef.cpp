import ezs.tfl.Ref;
using namespace ezs::tfl;
namespace {

struct Foo { };
static_assert(Ref<Foo &>);
static_assert(Ref<Foo &&>);
static_assert(!Ref<Foo>);

} // namespace 
