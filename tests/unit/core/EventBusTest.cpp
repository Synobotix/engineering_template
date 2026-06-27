#include "core/EventBus.hpp"
#include <gtest/gtest.h>
#include <vector>

struct Ping { int value; };

class PingCounter final : public core::IEventHandler<Ping> {
public:
    void on(const Ping& p) noexcept override { received_.push_back(p.value); }
    const std::vector<int>& received() const { return received_; }
private:
    std::vector<int> received_;
};

TEST(EventBus, SubscribeAndPublish)
{
    core::EventBus<Ping> bus;
    PingCounter counter;
    bus.subscribe(counter);

    bus.publish({42});
    ASSERT_EQ(counter.received().size(), 1u);
    EXPECT_EQ(counter.received()[0], 42);
}

TEST(EventBus, MultipleSubscribers)
{
    core::EventBus<Ping> bus;
    PingCounter a, b;
    bus.subscribe(a);
    bus.subscribe(b);

    bus.publish({7});
    EXPECT_EQ(a.received().size(), 1u);
    EXPECT_EQ(b.received().size(), 1u);
}

TEST(EventBus, Unsubscribe)
{
    core::EventBus<Ping> bus;
    PingCounter counter;
    bus.subscribe(counter);
    bus.unsubscribe(counter);

    bus.publish({1});
    EXPECT_TRUE(counter.received().empty());
}

TEST(EventBus, SubscriberCount)
{
    core::EventBus<Ping, 4> bus;
    PingCounter a, b;
    EXPECT_EQ(bus.subscriber_count(), 0u);
    bus.subscribe(a);
    EXPECT_EQ(bus.subscriber_count(), 1u);
    bus.subscribe(b);
    EXPECT_EQ(bus.subscriber_count(), 2u);
    bus.unsubscribe(a);
    EXPECT_EQ(bus.subscriber_count(), 1u);
}

TEST(EventBus, FullBusReturnsTrue)
{
    core::EventBus<Ping, 2> bus;
    PingCounter a, b, c;
    EXPECT_TRUE(bus.subscribe(a));
    EXPECT_TRUE(bus.subscribe(b));
    EXPECT_FALSE(bus.subscribe(c)); // bus full
}

TEST(EventBus, ResubscribeAfterUnsubscribe)
{
    core::EventBus<Ping, 1> bus;
    PingCounter c;
    bus.subscribe(c);
    bus.unsubscribe(c);
    EXPECT_TRUE(bus.subscribe(c)); // slot freed — should succeed
    bus.publish({9});
    EXPECT_EQ(c.received().size(), 1u);
}
