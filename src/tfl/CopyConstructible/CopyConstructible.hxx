export module ezs.tfl.CopyConstructible;

namespace ezs::tfl {

export
template <typename T>
concept CopyConstructible = requires(T t) {
  T{t};
};

} // namespace ezs::tfl
