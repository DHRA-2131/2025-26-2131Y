#include "MotionControl/MotionHandler.hpp"


MotionHandler* MotionHandler::instance()
{
    static MotionHandler s_handler;
    return &s_handler;
}

int MotionHandler::requestControl(bool blocking)
{   
    if (!blocking) {
        if (m_mutex.take(0)) return 1;
        else return false;
    }
    m_mutex.take();
    return 1;
}

void MotionHandler::relinquishControl()
{
    m_mutex.give();
}