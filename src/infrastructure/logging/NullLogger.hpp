#pragma once

#include "core/ILogger.hpp"

namespace infrastructure::logging {

class NullLogger final : public core::ILogger {
public:
    void              log(std::string_view, core::LogSeverity) noexcept override {}
    void              set(core::LogSeverity)                   noexcept override {}
    core::LogSeverity get()                              const noexcept override { return core::LogSeverity::kError; }
};

} // namespace infrastructure::logging
