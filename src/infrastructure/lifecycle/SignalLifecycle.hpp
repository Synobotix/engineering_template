#pragma once

#include "core/ILifecycle.hpp"

namespace infrastructure::lifecycle {

class SignalLifecycle final : public core::ILifecycle {
public:
    bool start()            noexcept override;
    void stop()             noexcept override;
    bool is_running() const noexcept override;
};

} // namespace infrastructure::lifecycle
