#pragma once

#include <array>
#include <cstddef>

namespace core {

// Single-threaded ring buffer — add external locking for concurrent access.
template<typename T, std::size_t N>
class RingBuffer {
    static_assert(N > 0, "RingBuffer capacity must be > 0");

public:
    [[nodiscard]] bool push(const T& item) noexcept
    {
        if (is_full()) return false;
        buffer_[tail_] = item;
        tail_          = (tail_ + 1) % N;
        ++count_;
        return true;
    }

    [[nodiscard]] bool pop(T& out) noexcept
    {
        if (is_empty()) return false;
        out   = buffer_[head_];
        head_ = (head_ + 1) % N;
        --count_;
        return true;
    }

    [[nodiscard]] bool peek(T& out) const noexcept
    {
        if (is_empty()) return false;
        out = buffer_[head_];
        return true;
    }

    [[nodiscard]] bool        is_empty()           const noexcept { return count_ == 0; }
    [[nodiscard]] bool        is_full()            const noexcept { return count_ == N; }
    [[nodiscard]] std::size_t size()               const noexcept { return count_; }
    static constexpr std::size_t capacity()              noexcept { return N; }

    void clear() noexcept { head_ = tail_ = count_ = 0; }

private:
    std::array<T, N> buffer_{};
    std::size_t      head_{0};
    std::size_t      tail_{0};
    std::size_t      count_{0};
};

} // namespace core
