#pragma once

#include "pros/misc.h"
class ControllerJoystick{
    public:
        ControllerJoystick(pros::controller_analog_e_t Joystick, int DeadZone);

        
        double value();

    private:
        int m_deadZone;
        pros::controller_analog_e_t m_joystick;
};

extern ControllerJoystick velocityJoystick;
extern ControllerJoystick turningJoystick;
