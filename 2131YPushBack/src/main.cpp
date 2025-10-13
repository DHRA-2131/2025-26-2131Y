#include "main.h"
#include "pros/rtos.hpp"
#include "Chassis/Sensors/MotorEncoder.hpp"
#include "Chassis/Sensors/InertialSensor.hpp"
#include <iostream>


// Runs at Initialization of the Program
void initialize() 
{
    
}//initialize

// Runs while the program is disabled
void disabled() 
{

}//disabled

// 
void competition_initialize() 
{

}//competition_initalize


// Runs when Autonomous Control is Triggered
void autonomous() 
{

} //autonomous

// Runs when Driver Control is Triggered
pros::MotorGroup testDrive({21, 19, 10}, pros::v5::MotorGear::blue, pros::v5::MotorUnits::deg);
MotorEncoder testEncoder(testDrive);
void opcontrol() {
    while (true)
    {
        testEncoder.update(10.0f);
        std::cout << testEncoder.getAcceleration() << std::endl;
        pros::delay(10);
    }
} //opcontrol