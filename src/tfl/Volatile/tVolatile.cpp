import ezs.tfl.Volatile;

using namespace ezs::tfl;

namespace {

static_assert(!Volatile<int>);
static_assert(Volatile<volatile int>);
static_assert(!Volatile<const int>);

static_assert(!Volatile<int *>);
static_assert(!Volatile<volatile int *>);
static_assert(Volatile<int *volatile>);

static_assert(!Volatile<volatile int &>);
static_assert(!Volatile<int&>);

struct Foo {};
static_assert(!Volatile<Foo>);
static_assert(Volatile<volatile Foo>);

static_assert(Volatile<volatile int[]>);
static_assert(!Volatile<int[]>);

static_assert(Volatile<volatile void>);
static_assert(!Volatile<void>);

} // namespace
