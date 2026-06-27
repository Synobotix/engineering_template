#pragma once

#include "core/ILogger.hpp"

namespace infrastructure::logging {

enum class ColorMode { Auto, Always, Never };

class ConsoleLogger final : public core::ILogger {
public:
    explicit ConsoleLogger(
        core::LogSeverity min_severity = core::LogSeverity::kInfo,
        ColorMode         color_mode   = ColorMode::Auto
    ) noexcept;

    void              log(std::string_view message, core::LogSeverity severity) noexcept override;
    void              set(core::LogSeverity severity)                           noexcept override;
    core::LogSeverity get()                                               const noexcept override;

private:
    core::LogSeverity min_severity_;
    bool              colors_enabled_;
};

} // namespace infrastructure::logging
