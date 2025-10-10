#include "DriverControl/Controller.hpp"
#include "Chassis/Chassis.hpp"
#include "pros/misc.h"


Controller::Controller(pros::controller_id_e_t id)
    : prosController(id)
{}

void Controller::setCallback(pros::controller_digital_e_t button, std::function<void(bool)> callbackFunction)
{
    m_callbacks.push_back(std::make_pair(button, callbackFunction));
}

void Controller::setAnalogFunction(std::function<void(int,int,int,int)> analogFunction)
{
    m_analogFunction = analogFunction;
}

void Controller::update()
{
    for (int i; i < m_callbacks.size(); i++){
        // Call function at i (which is second in pair) passing in the value of the button specified by the first of pair
        m_callbacks.at(i).second(prosController.get_digital(m_callbacks.at(i).first));
    }

    
    int Rx = prosController.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_X);
    int Ry = prosController.get_analog(pros::E_CONTROLLER_ANALOG_RIGHT_Y);
    int Lx = prosController.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
    int Ly = prosController.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
    m_analogFunction(Rx,Ry,Lx,Ly);
}


/* Default analog controls */
void Controller::tank(int Rx, int Ry, int Lx, int Ly)
{   
    DriveBase::instance()->setMotors(Ry, Ly);
}

void Controller::splitArcade(int Rx, int Ry, int Lx, int Ly)
{
    DriveBase::instance()->setMotors(Ly-Rx,Ly+Rx);
}
