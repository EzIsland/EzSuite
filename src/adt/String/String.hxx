export module ezs.adt.String;

import <type_traits>;
import <string>;

export namespace ezs::adt {


       template<typename T> concept String = std::is_convertible_v<T, std::string>;

} // namespace ezs::adt
