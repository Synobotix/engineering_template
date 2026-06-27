#pragma once

#include <cstdint>
#include <string_view>

namespace core {

class IMetrics {
public:
    virtual ~IMetrics() = default;

    virtual void increment(std::string_view name, uint64_t delta = 1) noexcept = 0;
    virtual void gauge    (std::string_view name, int64_t  value)     noexcept = 0;
    virtual void record   (std::string_view name, uint64_t value)     noexcept = 0;
};

} // namespace core
