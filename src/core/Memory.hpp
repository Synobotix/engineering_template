#pragma once

#include <memory_resource>
#include <cstddef>

namespace core::memory {

using Resource = std::pmr::memory_resource;

// Monotonic static pool — stack-allocated, no heap, no individual deallocation.
// Suited for embedded targets or any context where deterministic allocation is required.
//
// Usage:
//   core::memory::StaticPool<4096> pool;
//   inject &pool wherever a Resource* is expected
template<std::size_t N>
class StaticPool final : public std::pmr::memory_resource {
public:
    StaticPool() noexcept
        : pool_{buffer_, sizeof(buffer_), std::pmr::null_memory_resource()}
    {}

    StaticPool(const StaticPool&)            = delete;
    StaticPool& operator=(const StaticPool&) = delete;

    std::size_t capacity() const noexcept { return N; }

private:
    void* do_allocate(std::size_t bytes, std::size_t align) override
    {
        return pool_.allocate(bytes, align);
    }

    void do_deallocate(void* p, std::size_t bytes, std::size_t align) override
    {
        pool_.deallocate(p, bytes, align);
    }

    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override
    {
        return this == &other;
    }

    alignas(std::max_align_t) std::byte     buffer_[N]{};
    std::pmr::monotonic_buffer_resource     pool_;
};

// Returns the process-wide default resource (heap).
// Replace with a StaticPool at the composition root for embedded targets.
inline Resource* default_resource() noexcept
{
    return std::pmr::get_default_resource();
}

} // namespace core::memory
