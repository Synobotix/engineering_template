#pragma once

#include "core/IHealth.hpp"
#include <array>
#include <cstddef>
#include <functional>
#include <optional>

namespace infrastructure::health {

template<std::size_t MaxProviders = 16>
class HealthRegistry final : public core::IHealth {
public:
    void register_provider(core::IHealthProvider& provider) noexcept override
    {
        for (auto& slot : providers_) {
            if (!slot.has_value()) {
                slot.emplace(provider);
                return;
            }
        }
    }

    core::HealthStatus overall() const noexcept override
    {
        core::HealthStatus worst = core::HealthStatus::Healthy;
        for (const auto& slot : providers_) {
            if (!slot.has_value()) continue;
            core::HealthStatus s = slot->get().check();
            if (s == core::HealthStatus::Unhealthy) return s;
            if (s == core::HealthStatus::Degraded)  worst = s;
        }
        return worst;
    }

private:
    using Slot = std::optional<std::reference_wrapper<core::IHealthProvider>>;
    std::array<Slot, MaxProviders> providers_{};
};

} // namespace infrastructure::health
