#pragma once

#include "core/IQueue.hpp"
#include <array>
#include <mutex>

namespace infrastructure::concurrency {

template<typename T, std::size_t N>
class StdQueue final : public core::IQueue<T> {
public:
    bool push(const T& item) noexcept override
    {
        std::lock_guard<std::mutex> lock{mutex_};
        if (count_ >= N) return false;
        buffer_[(head_ + count_) % N] = item;
        ++count_;
        return true;
    }

    bool pop(T& item) noexcept override
    {
        std::lock_guard<std::mutex> lock{mutex_};
        if (count_ == 0) return false;
        item  = buffer_[head_];
        head_ = (head_ + 1) % N;
        --count_;
        return true;
    }

    bool        is_empty()  const noexcept override { std::lock_guard<std::mutex> l{mutex_}; return count_ == 0; }
    bool        is_full()   const noexcept override { std::lock_guard<std::mutex> l{mutex_}; return count_ >= N; }
    std::size_t size()      const noexcept override { std::lock_guard<std::mutex> l{mutex_}; return count_; }
    std::size_t capacity()  const noexcept override { return N; }

private:
    mutable std::mutex mutex_;
    std::array<T, N>   buffer_{};
    std::size_t        head_{0};
    std::size_t        count_{0};
};

} // namespace infrastructure::concurrency
