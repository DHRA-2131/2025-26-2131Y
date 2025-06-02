#pragma once

#include "pros/misc.h"


class ControllerJoystick
{
    public:

        /**
        * @brief Controller Joystick Constructor
        * 
        * @param Joystick
        * @param DeadZone
        * @param Scale
        */
        ControllerJoystick(pros::controller_analog_e_t Joystick, int DeadZone, double Scale);

        /**
         * @brief Return Scaled value of joystick
         *
         */
        double value();

    private:
        int m_deadZone;
        double m_scale;
        pros::controller_analog_e_t m_joystick;
};

extern ControllerJoystick linearJoystick;
extern ControllerJoystick angularJoystick;
