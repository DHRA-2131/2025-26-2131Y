#include "Chassis/ControllerInput.hpp"
#include "Competition/RobotConfig.hpp"
#include "pros/misc.h"
#include "math.h"
#include "Utilities/logging.hpp"

ControllerJoystick::ControllerJoystick(pros::controller_analog_e_t Joystick, int DeadZone, double Scale) : m_joystick(Joystick), m_deadZone(DeadZone), m_scale(Scale)
{}

double ControllerJoystick::value(){
    double value;
    (std::fabs(mainController.get_analog(m_joystick)) > m_deadZone) ? value = mainController.get_analog(m_joystick)*m_scale : value = 0;
    log(logLocation::MAIN, "%d", value);

    return value;
}


ControllerButton::ControllerButton(pros::controller_digital_e_t Button, bool Inverted) : m_button(Button), m_inverted(Inverted)
{}

bool ControllerButton::value(){
    (m_inverted) ? (!mainController.get_digital(m_button)) : (mainController.get_digital(m_button));
}

ControllerJoystick linearJoystick(pros::E_CONTROLLER_ANALOG_LEFT_Y, 0, 1);
ControllerJoystick angularJoystick(pros::E_CONTROLLER_ANALOG_RIGHT_X, 0, 0.75);
