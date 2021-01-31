import ezs.tfl.ForwardRefOf;

import ezs.tfl.SameAs;

using namespace ezs::tfl;

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
