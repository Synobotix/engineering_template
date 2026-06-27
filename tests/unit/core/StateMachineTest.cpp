#include "core/StateMachine.hpp"
#include <gtest/gtest.h>

enum class State { Idle, Running, Stopped };
enum class Event { Start, Stop, Reset };

using FSM = core::StateMachine<State, Event>;

TEST(StateMachine, InitialState)
{
    FSM sm{State::Idle};
    EXPECT_EQ(sm.current(), State::Idle);
}

TEST(StateMachine, ValidTransition)
{
    FSM sm{State::Idle};
    sm.add(State::Idle,    Event::Start, State::Running);
    sm.add(State::Running, Event::Stop,  State::Stopped);

    EXPECT_TRUE(sm.process(Event::Start));
    EXPECT_EQ(sm.current(), State::Running);

    EXPECT_TRUE(sm.process(Event::Stop));
    EXPECT_EQ(sm.current(), State::Stopped);
}

TEST(StateMachine, UnknownEventReturnsFalse)
{
    FSM sm{State::Idle};
    sm.add(State::Idle, Event::Start, State::Running);

    EXPECT_FALSE(sm.process(Event::Stop)); // no transition from Idle on Stop
    EXPECT_EQ(sm.current(), State::Idle);  // state unchanged
}

TEST(StateMachine, WrongStateEventReturnsFalse)
{
    FSM sm{State::Running};
    sm.add(State::Idle, Event::Start, State::Running);

    EXPECT_FALSE(sm.process(Event::Start)); // not in Idle
    EXPECT_EQ(sm.current(), State::Running);
}

TEST(StateMachine, AddReturnsFalseWhenFull)
{
    core::StateMachine<State, Event, 2> sm{State::Idle};
    EXPECT_TRUE(sm.add(State::Idle,    Event::Start, State::Running));
    EXPECT_TRUE(sm.add(State::Running, Event::Stop,  State::Stopped));
    EXPECT_FALSE(sm.add(State::Stopped, Event::Reset, State::Idle)); // table full
}

TEST(StateMachine, FirstMatchingTransitionWins)
{
    FSM sm{State::Idle};
    sm.add(State::Idle, Event::Start, State::Running);
    sm.add(State::Idle, Event::Start, State::Stopped); // duplicate — ignored

    sm.process(Event::Start);
    EXPECT_EQ(sm.current(), State::Running);
}
