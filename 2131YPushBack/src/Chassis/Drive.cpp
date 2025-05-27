#include "Chassis/Drive.hpp"

#include "Competition/RobotConfig.hpp"



Drive::Drive(pros::MotorGroup& leftSideGroup, pros::MotorGroup& rightSideGroup, Odom& driveOdom) : 
leftSide(leftSideGroup), 
rightSide(rightSideGroup),  
m_driveOdom(driveOdom)
{

}

void Drive::driveVoltage(double leftVoltage, double rightVoltage){

    /* Use move_voltage instead of move bc move goes from -127 to 127 instead of -12v to 12v */

    this->leftSide.move_voltage(leftVoltage*1000); // *1000 because it takes in millivolts
    this->rightSide.move_voltage(rightVoltage*1000);
   
}

Odom testOdom;
Drive chassis(leftDrive, rightDrive, testOdom);