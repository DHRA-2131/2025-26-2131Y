#include "Util/Timer.hpp"
#include "pros/rtos.hpp"
#include <cstdint>
#include <iostream>

Timer::Timer() 
    : m_startTime(pros::millis())
{}

Timer::~Timer()
{
    std::cout << *this << std::endl;
}

uint32_t Timer::getCurrentTime()
{
    return pros::millis()-m_startTime;
}

std::ostream& operator<<(std::ostream& os, Timer& printTimer)
{
    os << printTimer.getCurrentTime(); 
    return os;
}
