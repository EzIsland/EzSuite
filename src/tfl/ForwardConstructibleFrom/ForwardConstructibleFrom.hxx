export module ezs.tfl.ForwardConstructibleFrom;

import ezs.tfl.forward;

namespace ezs::tfl {

export
template <typename T, typename... Args>
concept ForwardConstructibleFrom = requires(Args&&... pArgs) {
  T{tfl::forward<Args>(pArgs)...};
};

} // namespace ezs::tfl
