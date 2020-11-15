export module ezs.adt.Variant;
export
namespace ezs::adt {
class Variant final {
public:
constexpr Variant() noexcept = delete;
constexpr Variant(const Variant&) noexcept = delete;
constexpr Variant(Variant&&) noexcept = delete;
constexpr Variant& operator=(const Variant&) & noexcept = delete;
constexpr Variant& operator=(Variant&&) & noexcept = delete;
constexpr ~Variant() noexcept = delete;
};
} // namespace 