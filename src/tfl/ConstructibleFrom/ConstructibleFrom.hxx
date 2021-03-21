export module ezs.tfl.ConstructibleFrom;

namespace ezs::tfl {
export
template <typename T, typename... Args>
concept ConstructibleFrom = requires(Args... pArgs) {
  T{pArgs...};
};

} // namespace ezs::tfl
