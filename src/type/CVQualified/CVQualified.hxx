export module ezs.type.CVQualified;

import ezs.type.Const;
import ezs.type.Volatile;
    
export
namespace ezs::type {
template<typename T> concept CVQualified = Const<T> || Volatile<T>;
}
