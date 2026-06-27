#pragma once

#include <array>
#include <cstddef>
#include <functional>
#include <optional>

namespace core {

template<typename Event>
class IEventHandler {
public:
    virtual ~IEventHandler() = default;
    virtual void on(const Event& event) noexcept = 0;
};

template<typename Event, std::size_t MaxHandlers = 8>
class EventBus {
    using Slot = std::optional<std::reference_wrapper<IEventHandler<Event>>>;

public:
    bool subscribe(IEventHandler<Event>& handler) noexcept
    {
        for (auto& slot : handlers_) {
            if (!slot.has_value()) {
                slot.emplace(handler);
                return true;
            }
        }
        return false;
    }

    void unsubscribe(IEventHandler<Event>& handler) noexcept
    {
        for (auto& slot : handlers_) {
            if (slot.has_value() && &slot->get() == &handler)
                slot.reset();
        }
    }

    void publish(const Event& event) const noexcept
    {
        for (const auto& slot : handlers_) {
            if (slot.has_value()) slot->get().on(event);
        }
    }

    std::size_t subscriber_count() const noexcept
    {
        std::size_t n = 0;
        for (const auto& slot : handlers_)
            if (slot.has_value()) ++n;
        return n;
    }

private:
    std::array<Slot, MaxHandlers> handlers_{};
};

} // namespace core
