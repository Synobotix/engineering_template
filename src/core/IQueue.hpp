#pragma once

#include <cstddef>

namespace core {

template<typename T>
class IQueue {
public:
    virtual ~IQueue() = default;

    [[nodiscard]] virtual bool        push(const T& item)  noexcept = 0;
    [[nodiscard]] virtual bool        pop(T& item)         noexcept = 0;
    [[nodiscard]] virtual bool        is_empty()     const noexcept = 0;
    [[nodiscard]] virtual bool        is_full()      const noexcept = 0;
    [[nodiscard]] virtual std::size_t size()         const noexcept = 0;
    [[nodiscard]] virtual std::size_t capacity()     const noexcept = 0;
};

} // namespace core
