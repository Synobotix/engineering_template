#pragma once

#include "core/IMetrics.hpp"

namespace infrastructure::metrics {

class NullMetrics final : public core::IMetrics {
public:
    void increment(std::string_view, uint64_t) noexcept override {}
    void gauge    (std::string_view, int64_t)  noexcept override {}
    void record   (std::string_view, uint64_t) noexcept override {}
};

} // namespace infrastructure::metrics
