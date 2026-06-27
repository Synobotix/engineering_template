#pragma once

#include <cstdint>

namespace core {

class IClock {
public:
    virtual ~IClock() = default;

    [[nodiscard]] virtual uint64_t now_ms() const noexcept = 0;
};

} // namespace core
