export module ezs.type.Value;

import ezs.type.Object;
import ezs.type.CVQualified;
    
export
namespace ezs::type {

template<typename T> concept Value = Object<T> && !CVQualified<T>;

}
