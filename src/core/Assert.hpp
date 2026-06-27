#pragma once

#include <cstdio>
#include <cstdlib>

namespace core {

using AssertHandler = void(*)(const char* expr, const char* file, int line) noexcept;

namespace detail {

    inline AssertHandler& assert_handler() noexcept
    {
        static AssertHandler h = nullptr;
        return h;
    }

    inline void handle_assert(const char* expr, const char* file, int line) noexcept
    {
        if (auto h = assert_handler()) {
            h(expr, file, line);
        } else {
            std::fprintf(stderr, "Assertion failed: %s (%s:%d)\n", expr, file, line);
            std::abort();
        }
    }

} // namespace detail

inline void set_assert_handler(AssertHandler handler) noexcept
{
    detail::assert_handler() = handler;
}

} // namespace core

#ifndef NDEBUG
#  define CORE_PRECONDITION(expr)  ((expr) ? void(0) : ::core::detail::handle_assert(#expr, __FILE__, __LINE__))
#  define CORE_POSTCONDITION(expr) ((expr) ? void(0) : ::core::detail::handle_assert(#expr, __FILE__, __LINE__))
#  define CORE_INVARIANT(expr)     ((expr) ? void(0) : ::core::detail::handle_assert(#expr, __FILE__, __LINE__))
#else
#  define CORE_PRECONDITION(expr)  (void)(sizeof(expr))
#  define CORE_POSTCONDITION(expr) (void)(sizeof(expr))
#  define CORE_INVARIANT(expr)     (void)(sizeof(expr))
#endif
