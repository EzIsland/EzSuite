export module ezs.adt.NotStandardLayout;
export
namespace ezs::adt {

template<typename T>       
class NotStandardLayout final {
public:
  constexpr NotStandardLayout() noexcept = default;
  constexpr NotStandardLayout(const NotStandardLayout&) noexcept = default;
  constexpr NotStandardLayout(NotStandardLayout&&) noexcept = default;
  constexpr NotStandardLayout& operator=(const NotStandardLayout&) & noexcept = default;
  constexpr NotStandardLayout& operator=(NotStandardLayout&&) & noexcept = default;
  constexpr ~NotStandardLayout() noexcept = default;

 protected:
  struct ProtectedEmpty { };
  [[no_unique_address]] ProtectedEmpty mProtectedEmpty;
  
 private:
  struct PrivateEmpty { };
  [[no_unique_address]] PrivateEmpty mPrivateEmpty;
};
} // namespace

