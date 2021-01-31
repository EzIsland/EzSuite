export module ezs.tfl.Object;

import <type_traits>;

export
namespace ezs::tfl {

template <typename T>
concept Object = std::is_object_v<T>;

} // namespace ezs::tfl
