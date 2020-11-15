export module ezs.type.Object;

import <type_traits>;

export
namespace ezs::type {

template <typename T>
concept Object = std::is_object_v<T>;

} // namespace ezs::type
