#pragma once

#include "core/ILogger.hpp"

#include <string>
#include <vector>

namespace test {

struct LogEntry {
    std::string       message;
    core::LogSeverity severity;
};

class MockLogger final : public core::ILogger {
public:
    void log(std::string_view message, core::LogSeverity severity) noexcept override
    {
        entries_.push_back({std::string(message), severity});
    }

    void              set(core::LogSeverity sev) noexcept override { min_ = sev; }
    core::LogSeverity get()                const noexcept override { return min_; }

    const std::vector<LogEntry>& entries() const noexcept { return entries_; }
    void clear() noexcept { entries_.clear(); }

    bool has(core::LogSeverity sev, std::string_view substr) const
    {
        for (const auto& e : entries_)
            if (e.severity == sev && e.message.find(substr) != std::string::npos)
                return true;
        return false;
    }

private:
    std::vector<LogEntry> entries_;
    core::LogSeverity     min_{core::LogSeverity::kDebug};
};

} // namespace test
