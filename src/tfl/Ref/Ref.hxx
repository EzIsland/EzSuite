export module ezs.tfl.Ref;
import ezs.tfl.RValueRef;
import ezs.tfl.LValueRef;

export
namespace ezs::tfl {

template<typename T> concept Ref = RValueRef<T> || LValueRef<T>;

} // namespace 
