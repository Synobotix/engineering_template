#include "infrastructure/logging/ConsoleLogger.hpp"

#include <cstdio>

#ifdef _WIN32
#  include <io.h>
#  define STDERR_IS_TTY() (_isatty(_fileno(stderr)) != 0)
#else
#  include <unistd.h>
#  define STDERR_IS_TTY() (isatty(STDERR_FILENO) != 0)
#endif

namespace infrastructure::logging {

namespace {

struct SeverityMeta {
    const char* label;
    const char* color;  // ANSI escape sequence
};

// kWarning uses 256-color orange (208); falls back gracefully on basic terminals
constexpr SeverityMeta k_meta[] = {
    {"DEBUG",   "\033[36m"},        // cyan
    {"VERBOSE", "\033[2m"},         // dim
    {"INFO",    "\033[32m"},        // green
    {"WARN",    "\033[38;5;208m"},  // orange
    {"ERROR",   "\033[1;31m"},      // bold red
};
constexpr const char* k_reset = "\033[0m";

const SeverityMeta& meta_for(core::LogSeverity s) noexcept
{
    return k_meta[static_cast<int>(s)];
}

} // namespace

ConsoleLogger::ConsoleLogger(core::LogSeverity min_severity, ColorMode color_mode) noexcept
    : min_severity_(min_severity)
    , colors_enabled_(color_mode == ColorMode::Always ||
                     (color_mode == ColorMode::Auto && STDERR_IS_TTY()))
{}

void ConsoleLogger::log(std::string_view message, core::LogSeverity severity) noexcept
{
    if (severity < min_severity_) return;

    const auto& m = meta_for(severity);

    if (colors_enabled_) {
        std::fprintf(stderr, "%s[%s]%s %.*s\n",
            m.color,
            m.label,
            k_reset,
            static_cast<int>(message.size()),
            message.data());
    } else {
        std::fprintf(stderr, "[%s] %.*s\n",
            m.label,
            static_cast<int>(message.size()),
            message.data());
    }
}

void ConsoleLogger::set(core::LogSeverity severity) noexcept { min_severity_ = severity; }
core::LogSeverity ConsoleLogger::get() const noexcept { return min_severity_; }

} // namespace infrastructure::logging
