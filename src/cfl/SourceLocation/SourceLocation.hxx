export module ezs.cfl.SourceLocation;
import ezs.uint_t;
import<source_location>;
import<string>;

export
namespace ezs::cfl {

///
/// \brief The SourceLocation class represents information about a location in
/// the source code including a line, column, file name, and function name.
///
class SourceLocation final {
 public:
  [[nodiscard]] constexpr uint_t getLine() const noexcept;
  [[nodiscard]] constexpr uint_t getColumn() const noexcept;
  [[nodiscard]] inline std::string getFileName() const noexcept;
  [[nodiscard]] inline std::string getFunctionName() const noexcept;
  [[nodiscard]] static constexpr SourceLocation current(const std::source_location& pLocation = std::source_location::current()) noexcept;

  ///
  /// \brief Default constructor is deleted.
  ///
  [[nodiscard]] constexpr explicit SourceLocation() noexcept = delete;
  
  [[nodiscard]] constexpr explicit SourceLocation(const SourceLocation&) noexcept = default;
  [[nodiscard]] constexpr explicit SourceLocation(SourceLocation&&) noexcept = default;
  SourceLocation& operator=(const SourceLocation&) &noexcept = default;
  constexpr SourceLocation& operator=(SourceLocation&&) &noexcept = default;
  constexpr ~SourceLocation() noexcept = default;
 private:
  std::source_location mLocation;

  ///
  /// \brief Private constructor.
  ///
  [[nodiscard]] constexpr explicit SourceLocation(const std::source_location&) noexcept;
};

[[nodiscard]] constexpr uint_t SourceLocation::getLine() const noexcept {
  return mLocation.line();
}
[[nodiscard]] constexpr uint_t SourceLocation::getColumn() const noexcept {
  return mLocation.column();
}
[[nodiscard]] std::string SourceLocation::getFileName() const noexcept {
  return mLocation.file_name();
}
[[nodiscard]] std::string SourceLocation::getFunctionName() const noexcept {
  return mLocation.function_name();
}
[[nodiscard]] constexpr SourceLocation SourceLocation::current(const std::source_location& pLocation) noexcept {
  return SourceLocation{pLocation};
}
[[nodiscard]] constexpr SourceLocation::SourceLocation(const std::source_location& pLocation) noexcept
    : mLocation(pLocation) {
}
} // namespace ezs::cfl
