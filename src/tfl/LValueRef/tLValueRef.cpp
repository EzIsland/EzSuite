import ezs.tfl.LValueRef;

using namespace ezs::tfl;

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
