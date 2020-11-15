import ezs.type.NonDeduced;
using namespace ezs::type;
namespace {

template<typename T> void foo(NonDeduced<T>) { }


template <typename T> concept InvalidInvocation = !requires(T x) { foo(x); };
template<typename T> concept ValidInvocation = requires(T x) { foo<T>(x); };

static_assert(InvalidInvocation<int>);
static_assert(ValidInvocation<int>);

} // namespace 
