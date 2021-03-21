export module ezs.tfl.MoveAssignable;

import ezs.tfl.move;
import ezs.tfl.declval;

namespace ezs::tfl {

export
template<typename T>
concept MoveAssignable = requires(T t) {
  t = tfl::move(tfl::declval<T>());
};

} // namespace ezs::tfl
