#pragma once

#include <variant>
#include <utility>

namespace core {

template<typename T, typename E>
class [[nodiscard]] Result {
public:
    static Result ok(T value)  { return Result{std::variant<T, E>{std::in_place_index<0>, std::move(value)}}; }
    static Result err(E error) { return Result{std::variant<T, E>{std::in_place_index<1>, std::move(error)}}; }

    bool is_ok()  const noexcept { return data_.index() == 0; }
    bool is_err() const noexcept { return data_.index() == 1; }

    T&       value()       { return std::get<0>(data_); }
    const T& value() const { return std::get<0>(data_); }
    E&       error()       { return std::get<1>(data_); }
    const E& error() const { return std::get<1>(data_); }

private:
    explicit Result(std::variant<T, E> data) : data_(std::move(data)) {}

    std::variant<T, E> data_;
};

} // namespace core
