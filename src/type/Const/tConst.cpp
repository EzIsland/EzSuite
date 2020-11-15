import ezs.type.Const;

using namespace ezs::type;

namespace {

static_assert(!Const<int>);
static_assert(Const<const int>);
static_assert(!Const<volatile int>);

static_assert(!Const<int *>);
static_assert(!Const<const int *>);
static_assert(Const<const int *const>);

static_assert(!Const<const int &>);
static_assert(!Const<int &>);

struct Foo { };
static_assert(Const<const Foo>);
static_assert(!Const<Foo>);

static_assert(Const<const int[]>);
static_assert(!Const<int[]>);

static_assert(Const<const void>);
static_assert(!Const<void>);

} // namespace
