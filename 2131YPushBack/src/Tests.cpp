#include "Chassis/Chassis.hpp"
#include "MotionControl/MotionHandler.hpp"
#include "pros/misc.h"
#include "pros/motor_group.hpp"

void MotionHandlerTest()
{
    MotionHandler::instance();
    pros::Task task([]{
            while(true){
            MotionHandler::instance()->requestControl();
            pros::delay(5000);
            MotionHandler::instance()->relinquishControl();
        }
        }); //pros::Task
    while(true){
        
        MotionHandler::instance()->requestControl();
        pros::delay(7000);
        MotionHandler::instance()->relinquishControl();
    }//while true
}

#include "DriverControl/Controller.hpp"
void tankArcadeButtonToggle(bool pressed);
Controller masterController(pros::E_CONTROLLER_MASTER);


void DriverControlTest()
{   
    pros::MotorGroup right({0,0,0});
    pros::MotorGroup left({0,0,0});
    DriveBase::instance()->init(right, left, nullptr);
    masterController.setCallback(pros::E_CONTROLLER_DIGITAL_A, tankArcadeButtonToggle);
    while(true){
        
    }
}

void tankArcadeButtonToggle(bool pressed)
{
    static bool s_toggle;
    static bool s_prevToggle;
    
    s_toggle = (pressed && !s_prevToggle) ? !s_toggle : s_toggle;
    s_prevToggle = pressed;

    if (s_toggle){
        masterController.setAnalogFunction(Controller::tank);
    }
    else 
    {
        masterController.setAnalogFunction(Controller::splitArcade);
    }
}

