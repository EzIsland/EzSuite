import ezs.type.ForwardRefOf;

import ezs.type.SameAs;

using namespace ezs::type;

namespace {

static_assert(ForwardRefOf<int, int>);
static_assert(ForwardRefOf<int&, int>);
static_assert(!ForwardRefOf<int&&, int>);

struct Foo { };
template <ForwardRefOf<Foo> T> T&& foo(T &&pArg) { return pArg; }

static_assert(SameAs<decltype(foo(Foo{})), Foo&&>);

Foo arg;
static_assert(SameAs<decltype(foo(arg)), Foo&>);



} // namespace
