#pragma once

#include <string_view>

namespace core {

enum class HealthStatus { Healthy, Degraded, Unhealthy };

class IHealthProvider {
public:
    virtual ~IHealthProvider() = default;

    [[nodiscard]] virtual std::string_view name()  const noexcept = 0;
    [[nodiscard]] virtual HealthStatus     check() const noexcept = 0;
};

class IHealth {
public:
    virtual ~IHealth() = default;

    virtual void                   register_provider(IHealthProvider& provider) noexcept = 0;
    [[nodiscard]] virtual HealthStatus overall()                           const noexcept = 0;
};

} // namespace core
