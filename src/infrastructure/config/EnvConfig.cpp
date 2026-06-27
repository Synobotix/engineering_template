#include "infrastructure/config/EnvConfig.hpp"
#include <cstdlib>
#include <cstring>

namespace infrastructure::config {

std::optional<std::string_view> EnvConfig::get(std::string_view key) const noexcept
{
    char buf[256];
    if (key.size() >= sizeof(buf)) return std::nullopt;
    std::memcpy(buf, key.data(), key.size());
    buf[key.size()] = '\0';

    const char* val = std::getenv(buf);
    if (!val) return std::nullopt;
    return std::string_view{val};
}

} // namespace infrastructure::config
