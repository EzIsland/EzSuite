import ezs.tfl.SelectType;
import ezs.tfl.SameAs;
import ezs.uint_t;

using namespace ezs::tfl;

namespace {

static_assert(SameAs<SelectType<0, char, short, int, long>, char>);
static_assert(SameAs<SelectType<1, char, short, int, long>, short>);
static_assert(SameAs<SelectType<2, char, short, int, long>, int>);
static_assert(SameAs<SelectType<3, char, short, int, long>, long>);

} // namespace 
