#pragma once

#include "core/IConfig.hpp"

namespace infrastructure::config {

class EnvConfig final : public core::IConfig {
public:
    std::optional<std::string_view> get(std::string_view key) const noexcept override;
};

} // namespace infrastructure::config
