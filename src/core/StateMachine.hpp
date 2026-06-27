#pragma once

#include <array>
#include <cstddef>

namespace core {

template<typename State, typename Event, std::size_t MaxTransitions = 16>
class StateMachine {
public:
    explicit StateMachine(State initial) noexcept : current_(initial) {}

    bool add(State from, Event on, State to) noexcept
    {
        if (count_ >= MaxTransitions) return false;
        transitions_[count_++] = {from, on, to};
        return true;
    }

    bool process(const Event& event) noexcept
    {
        for (std::size_t i = 0; i < count_; ++i) {
            if (transitions_[i].from == current_ && transitions_[i].on == event) {
                current_ = transitions_[i].to;
                return true;
            }
        }
        return false;
    }

    const State& current() const noexcept { return current_; }

private:
    struct Transition { State from; Event on; State to; };

    std::array<Transition, MaxTransitions> transitions_{};
    std::size_t count_{0};
    State       current_;
};

} // namespace core
