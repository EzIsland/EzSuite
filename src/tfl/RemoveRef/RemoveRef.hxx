export module ezs.tfl.RemoveRef;
import ezs.tfl.RemoveRValueRef;
import ezs.tfl.RemoveLValueRef;

export
namespace ezs::tfl {

template<typename T> using RemoveRef = RemoveRValueRef<RemoveLValueRef<T>>;

} // namespace 
