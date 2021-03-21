export module ezs.cfl.assert;

import<source_location>;
import<string>;

export
namespace ezs::cfl {

void assert(bool pAssert, const std::source_location &pLocation =
                              std::source_location::current());
void assert(
    bool pAssert, const std::string &pMessage,
    const std::source_location &pLocation = std::source_location::current());

void assert(bool pAssert,
            const char* pMessage,
            const std::source_location &pLocation =
            std::source_location::current());


} // namespace ezs::cfl
