import ezs.type.CVQualified;

using namespace ezs::type;

namespace {

struct Foo {};

static_assert(!CVQualified<int>);
static_assert(CVQualified<const int>);

static_assert(!CVQualified<int *>);
static_assert(!CVQualified<const int *>);
static_assert(CVQualified<const int *const>);

static_assert(!CVQualified<const int &>);
static_assert(!CVQualified<int &>);

static_assert(CVQualified<const Foo>);
static_assert(!CVQualified<Foo>);

static_assert(CVQualified<const int[]>);
static_assert(!CVQualified<int[]>);

static_assert(CVQualified<const void>);
static_assert(!CVQualified<void>);

static_assert(!CVQualified<int>);
static_assert(CVQualified<volatile int>);

static_assert(!CVQualified<int *>);
static_assert(!CVQualified<volatile int *>);
static_assert(CVQualified<int *volatile>);

static_assert(!CVQualified<volatile int &>);
static_assert(!CVQualified<int&>);

static_assert(!CVQualified<Foo>);
static_assert(CVQualified<volatile Foo>);

static_assert(CVQualified<volatile int[]>);
static_assert(!CVQualified<int[]>);

static_assert(CVQualified<volatile void>);
static_assert(!CVQualified<void>);

static_assert(CVQualified<const volatile int>);
static_assert(!CVQualified<const volatile int *>);
static_assert(CVQualified<const volatile Foo>);

} // namespace
