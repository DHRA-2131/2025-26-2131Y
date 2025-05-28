#include "Chassis/ControllerInput.hpp"
#include "Competition/RobotConfig.hpp"
#include "pros/misc.h"
#include "math.h"

ControllerJoystick::ControllerJoystick(pros::controller_analog_e_t Joystick, int DeadZone) : m_joystick(Joystick), m_deadZone(DeadZone)
{}

double ControllerJoystick::value(){
    double value;
    (std::fabs(mainController.get_analog(m_joystick)) > m_deadZone) ? value = mainController.get_analog(m_joystick) : value = 0;

    return value;
}

ControllerJoystick velocityJoystick(pros::E_CONTROLLER_ANALOG_LEFT_Y, 50);
ControllerJoystick turningJoystick(pros::E_CONTROLLER_ANALOG_RIGHT_X, 50);
