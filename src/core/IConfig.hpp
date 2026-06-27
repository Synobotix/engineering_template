#pragma once

#include <optional>
#include <string_view>

namespace core {

class IConfig {
public:
    virtual ~IConfig() = default;

    [[nodiscard]] virtual std::optional<std::string_view> get(std::string_view key) const noexcept = 0;

    [[nodiscard]] std::string_view get_or(std::string_view key, std::string_view default_value) const noexcept
    {
        auto val = get(key);
        return val.has_value() ? *val : default_value;
    }
};

} // namespace core
