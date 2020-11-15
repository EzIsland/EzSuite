import ezs.type.RValueRef;

using namespace ezs::type;

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
