export module ezs.type.Ref;
import ezs.type.RValueRef;
import ezs.type.LValueRef;

export
namespace ezs::type {

template<typename T> concept Ref = RValueRef<T> || LValueRef<T>;

} // namespace 
