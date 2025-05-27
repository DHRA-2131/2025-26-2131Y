#include "Chassis/Drive.hpp"

#include "Competition/RobotConfig.hpp"
#include "Utilities/PID.hpp"
#include "Utilities/ExitConditions.hpp"



Drive::Drive(pros::MotorGroup& leftSideGroup, pros::MotorGroup& rightSideGroup, Pose& startingPose, PID& lateralPID, PID& angularPID, Odom& driveOdom) : 
leftSide(leftSideGroup), 
rightSide(rightSideGroup),
currentPose(startingPose),
m_lateralPID(lateralPID),
m_angularPID(angularPID),
m_driveOdom(driveOdom)
{

}

void Drive::driveVoltage(double leftVoltage, double rightVoltage){

    /* Use move_voltage instead of move bc move goes from -127 to 127 instead of -12v to 12v */

    this->leftSide.move_voltage(leftVoltage*1000); // *1000 because it takes in millivolts
    this->rightSide.move_voltage(rightVoltage*1000);
   
}

void Drive::turnToAbsoluteHeading(double targetHeading){
    /* Set up turning paramters*/
    ExitCondition settledExit(0,0,0);
    ExitCondition velocitySettleExit(0,0,0);
    double error;
    double prev_error;
    do {
    error = targetHeading - currentPose.theta;
    
    
    } while (!settledExit.canExit(error) && !velocitySettleExit.canExit(error-prev_error));


}

Odom testOdom;
Pose testPose(0,0,0);


Drive chassis(leftDrive, rightDrive, testPose, lateralPID, angularPID,testOdom);