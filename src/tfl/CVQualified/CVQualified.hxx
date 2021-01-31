export module ezs.tfl.CVQualified;

import ezs.tfl.Const;
import ezs.tfl.Volatile;
    
export
namespace ezs::tfl {
template<typename T> concept CVQualified = Const<T> || Volatile<T>;
}
