#pragma once

#include "pros/misc.h"
class ControllerJoystick
{
    public:
        ControllerJoystick(pros::controller_analog_e_t Joystick, int DeadZone, double Scale);

        
        double value();

    private:
        int m_deadZone;
        double m_scale;
        pros::controller_analog_e_t m_joystick;
};

extern ControllerJoystick linearJoystick;
extern ControllerJoystick angularJoystick;
