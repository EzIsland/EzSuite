export module ezs.type.RemoveRef;
import ezs.type.RemoveRValueRef;
import ezs.type.RemoveLValueRef;

export
namespace ezs::type {

template<typename T> using RemoveRef = RemoveRValueRef<RemoveLValueRef<T>>;

} // namespace 
