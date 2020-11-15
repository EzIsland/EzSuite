import ezs.type.LValueRef;

using namespace ezs::type;

namespace {

static_assert(LValueRef<int &>);
static_assert(!LValueRef<int &&>);
static_assert(!LValueRef<int>);

static_assert(LValueRef<const int &>);
static_assert(!LValueRef<const int &&>);
static_assert(!LValueRef<const int>);

struct Foo { };
static_assert(LValueRef<Foo &>);
static_assert(!LValueRef<Foo &&>);
static_assert(!LValueRef<Foo>);

}
