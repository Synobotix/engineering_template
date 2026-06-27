#pragma once

#include <cstdint>
#include <cstdio>
#include <cstring>
#include <string_view>

namespace core {

enum class LogSeverity { kDebug, kVerbose, kInfo, kWarning, kError };

class LogStream; // forward declaration — defined below

class ILogger {
public:
    virtual ~ILogger() = default;

    virtual void        log(std::string_view message, LogSeverity severity) noexcept = 0;
    virtual void        set(LogSeverity severity)                           noexcept = 0;
    virtual LogSeverity get()                                         const noexcept = 0;

    // Stream factories — bodies defined after LogStream
    LogStream debug()   noexcept;
    LogStream verbose() noexcept;
    LogStream info()    noexcept;
    LogStream warning() noexcept;
    LogStream error()   noexcept;
};

// ---------------------------------------------------------------------------

class LogStream {
public:
    LogStream(ILogger& logger, LogSeverity severity) noexcept
        : logger_(logger), severity_(severity) {}

    ~LogStream() noexcept
    {
        if (pos_ > 0)
            logger_.log(std::string_view{buffer_, pos_}, severity_);
    }

    LogStream(const LogStream&)            = delete;
    LogStream& operator=(const LogStream&) = delete;
    LogStream(LogStream&&)                 = default;
    LogStream& operator=(LogStream&&)      = delete;

    LogStream& operator<<(std::string_view sv) noexcept { append(sv.data(), sv.size()); return *this; }
    LogStream& operator<<(const char* s)        noexcept { if (s) append(s, std::strlen(s)); return *this; }
    LogStream& operator<<(char c)               noexcept { append(&c, 1);                    return *this; }
    LogStream& operator<<(bool v)               noexcept { return *this << (v ? "true" : "false"); }
    LogStream& operator<<(int32_t v)            noexcept { return fmt("%d",   v); }
    LogStream& operator<<(uint32_t v)           noexcept { return fmt("%u",   v); }
    LogStream& operator<<(int64_t v)            noexcept { return fmt("%lld", static_cast<long long>(v)); }
    LogStream& operator<<(uint64_t v)           noexcept { return fmt("%llu", static_cast<unsigned long long>(v)); }
    LogStream& operator<<(float v)              noexcept { return fmt("%.6g", static_cast<double>(v)); }
    LogStream& operator<<(double v)             noexcept { return fmt("%.6g", v); }

private:
    static constexpr std::size_t kCapacity = 256;

    void append(const char* data, std::size_t len) noexcept
    {
        std::size_t space   = kCapacity - pos_;
        std::size_t to_copy = (len < space) ? len : space;
        std::memcpy(buffer_ + pos_, data, to_copy);
        pos_ += to_copy;
    }

    template<typename... Args>
    LogStream& fmt(const char* format, Args... args) noexcept
    {
        char tmp[64];
        int n = std::snprintf(tmp, sizeof(tmp), format, args...);
        if (n > 0) append(tmp, static_cast<std::size_t>(n));
        return *this;
    }

    ILogger&    logger_;
    LogSeverity severity_;
    char        buffer_[kCapacity]{};
    std::size_t pos_{0};
};

// ---------------------------------------------------------------------------
// ILogger stream factory bodies — defined here because LogStream is now complete

inline LogStream ILogger::debug()   noexcept { return {*this, LogSeverity::kDebug};   }
inline LogStream ILogger::verbose() noexcept { return {*this, LogSeverity::kVerbose}; }
inline LogStream ILogger::info()    noexcept { return {*this, LogSeverity::kInfo};    }
inline LogStream ILogger::warning() noexcept { return {*this, LogSeverity::kWarning}; }
inline LogStream ILogger::error()   noexcept { return {*this, LogSeverity::kError};   }

} // namespace core
