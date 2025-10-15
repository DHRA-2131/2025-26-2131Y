#include "main.h"

#include "Chassis/Sensors/MotorEncoder.hpp"
#include "pros/motor_group.hpp"
#include "Chassis/TrackingWheel.hpp"
#include "Chassis/Sensors/InertialSensor.hpp"
#include "Chassis/Localizer.hpp"



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

InertialSensor Gyro(20);
pros::MotorGroup testDrive({1, 2, 3}, pros::v5::MotorGearset::blue, pros::v5::MotorEncoderUnits::deg);
MotorEncoder testEncoder(testDrive);
TrackingWheel testWheel(testEncoder, 2.75f, 0.75f, {0, 0}, true);
Localizer testOdom(testWheel, Gyro, Pose(0, 0, 0));
void opcontrol() {
    while(true)
    {
        testOdom.update();
        std::cout << testOdom.getRobotPosition() << std::endl;
        pros::delay(10);
    }
} //opcontrol