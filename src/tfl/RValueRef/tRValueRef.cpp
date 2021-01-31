import ezs.tfl.RValueRef;

using namespace ezs::tfl;

namespace {

static_assert(!RValueRef<int &>);
static_assert(RValueRef<int &&>);
static_assert(!RValueRef<int>);

static_assert(!RValueRef<const int &>);
static_assert(RValueRef<const int &&>);
static_assert(!RValueRef<const int>);

struct Foo { };
static_assert(!RValueRef<Foo &>);
static_assert(RValueRef<Foo &&>);
static_assert(!RValueRef<Foo>);

} // namespace
