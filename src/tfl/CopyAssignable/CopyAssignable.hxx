export module ezs.tfl.CopyAssignable;

import ezs.tfl.declval;

namespace ezs::tfl {

export
template<typename T>
concept CopyAssignable = requires(T t) {
  t = tfl::declval<T>();
};

} // namespace ezs::tfl
