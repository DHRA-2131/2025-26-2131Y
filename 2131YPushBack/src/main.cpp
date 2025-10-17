#include "main.h"

#include "Chassis/Sensors/MotorEncoder.hpp"
#include "pros/motor_group.hpp"
#include "Chassis/TrackingWheel.hpp"
#include "Chassis/Sensors/InertialSensor.hpp"
#include "Chassis/Localizer.hpp"
#include "Chassis/Chassis.hpp"



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

extern void DriverControlTest();

InertialSensor Gyro(20);
pros::MotorGroup right({17,16,18});
pros::MotorGroup left({-10,-21,-19});

MotorEncoder testEncoder(right);
TrackingWheel testWheel(testEncoder, 2.75f, 0.75f, {6, 0}, true);
Localizer testOdom(testWheel, Gyro, Pose(0, 0, 0));
void opcontrol() {
    Gyro.reset(true);
    DriveBase::instance()->init(&right, &left, nullptr);
    while(true)
    {
        testOdom.update();
        //std::cout << testOdom.getRobotPosition() << std::endl;
        pros::delay(10);
    }
} //opcontrol