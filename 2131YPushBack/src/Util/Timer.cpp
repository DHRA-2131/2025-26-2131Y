#include "Util/Timer.hpp"
#include "pros/rtos.hpp"
#include <cstdint>
#include <ostream>

Timer::Timer() 
    : m_startTime(pros::millis())
{}



uint32_t Timer::getCurrentTime()
{
    return pros::millis()-m_startTime;
}

std::ostream& operator<<(std::ostream& os, Timer& printTimer)
{
    os << printTimer.getCurrentTime(); 
    return os;
}