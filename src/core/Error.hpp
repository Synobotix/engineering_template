#pragma once

#include <cstdint>
#include <string_view>

namespace core {

struct Error {
    int32_t          code;
    std::string_view message;

    constexpr Error(int32_t c, std::string_view m) noexcept : code(c), message(m) {}
    constexpr bool operator==(const Error& other) const noexcept { return code == other.code; }
    constexpr bool operator!=(const Error& other) const noexcept { return code != other.code; }
};

namespace errors {
    constexpr Error none     { 0, "no error"};
    constexpr Error unknown  {-1, "unknown error"};
    constexpr Error invalid  {-2, "invalid argument"};
    constexpr Error timeout  {-3, "timeout"};
    constexpr Error not_found{-4, "not found"};
} // namespace errors

} // namespace core
