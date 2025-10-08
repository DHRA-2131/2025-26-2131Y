#include "MotionControl/MotionHandler.hpp"


MotionHandler* MotionHandler::instance()
{
    static MotionHandler s_handler;
    return &s_handler;
}

int MotionHandler::requestControl(bool blocking)
{   
    if (!blocking && chassisBusy) return -1;
    chassisBusy = true;
    m_mutex.take();
    return 1;
}

void MotionHandler::relinquishControl()
{
    chassisBusy = false;
    m_mutex.give();
}