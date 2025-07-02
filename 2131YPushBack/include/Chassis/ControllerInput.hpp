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

class ControllerButton 
{

    public:
        ControllerButton(pros::controller_digital_e_t, bool Inverted);

        virtual bool value();

    private:
        pros::controller_digital_e_t m_button;
        bool m_inverted;
};



extern ControllerJoystick linearJoystick;
extern ControllerJoystick angularJoystick;

extern ControllerJoystick tankLeftJoystick;
extern ControllerJoystick tankRightJoystick;

extern ControllerButton intakeButton;
extern ControllerButton outtakeButton;
