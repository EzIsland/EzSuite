export module ezs.tfl.ForwardRef;

import ezs.tfl.Ref;
import ezs.tfl.LValueRef;

export
namespace ezs::tfl {

template <typename T>
concept ForwardRef = !Ref<T> || LValueRef<T>;

} // namespace 
