export module ezs.tfl.InstantiationOf;

namespace ezs::tfl {

namespace {

template <typename Instantiation, template <typename...> typename Template>
constexpr bool InstantiationOfImpl = false;

template <template <typename...> typename Template, typename... Ts>
constexpr bool InstantiationOfImpl<Template<Ts...>, Template> = true;

} // namespace

export
template <typename Instantiation, template <typename...> typename Template>
concept InstantiationOf = InstantiationOfImpl<Instantiation, Template>;

} // namespace ezs::tfl
