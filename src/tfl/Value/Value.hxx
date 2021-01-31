export module ezs.tfl.Value;

import ezs.tfl.Object;
import ezs.tfl.CVQualified;
    
export
namespace ezs::tfl {

template<typename T> concept Value = Object<T> && !CVQualified<T>;

}
