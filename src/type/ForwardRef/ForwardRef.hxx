export module ezs.type.ForwardRef;

import ezs.type.Ref;
import ezs.type.LValueRef;

export
namespace ezs::type {

template <typename T>
concept ForwardRef = !Ref<T> || LValueRef<T>;

} // namespace 
