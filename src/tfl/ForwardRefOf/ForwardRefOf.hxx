export module ezs.tfl.ForwardRefOf;

import ezs.tfl.Ref;
import ezs.tfl.SameAs;

export
namespace ezs::tfl {

template <typename T, typename Object>
concept ForwardRefOf = !Ref<Object> && (SameAs<Object&, T> || SameAs<Object, T>);

} // namespace ezs::tfl
