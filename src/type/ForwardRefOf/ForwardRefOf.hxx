export module ezs.type.ForwardRefOf;

import ezs.type.Ref;
import ezs.type.SameAs;

export
namespace ezs::type {

template <typename T, typename Object>
concept ForwardRefOf = !Ref<Object> && (SameAs<Object&, T> || SameAs<Object, T>);

} // namespace ezs::type
