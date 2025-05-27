#include "Chassis/Drive.hpp"

#include "Competition/RobotConfig.hpp"
#include "Utilities/PID.hpp"
#include "Utilities/ExitConditions.hpp"
#include "Utilities/Parameters.hpp"
#include "Utilities/Positioning.hpp"
#include "Utilities/mathUtils.hpp"




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

void Drive::turnToPoint(Point point, turningParameters turningSettings){
    //Calculate target heading
    double angle = toRad(std::atan2(point.y-this->currentPose.y, point.x-this->currentPose.y));
    
    //Error (wrapped between -180 and 180)
    angle = wrapAngle(angle - this->currentPose.theta);

    turnToAbsoluteHeading(angle, turningSettings);
}

void Drive::turnToAbsoluteHeading(double targetHeading, turningParameters turningSettings){
    /* Set up turning paramters*/
    ExitCondition settledExit(turningSettings.settleExitRange,turningSettings.settleExitTime,10);
    ExitCondition velocitySettleExit(turningSettings.velocitySettleExitRange,turningSettings.velocitySettleExitTime,10);
    double error = 0;
    double prev_error = 0;
    double prev_output = 0;

    m_angularPID.reset();

    do {

    //Prevent turning more than nessisary
    error = wrapAngle(targetHeading - currentPose.theta);
    
    double output = std::clamp(m_angularPID.calculate(error), -turningSettings.maxSpeed, turningSettings.maxSpeed);
    output = constrainAccel(output, prev_output, turningSettings.maxAccel);
    

    if (turningSettings.arc == arcDirection::arcToLeft) this->rightSide.move_voltage(output);
    else if (turningSettings.arc == arcDirection::arcToRight) this->leftSide.move_voltage(output);
    else {
        this->leftSide.move_voltage(-output);
        this->rightSide.move_voltage(output);
    }

    prev_error = error;
    prev_output = output;
    pros::delay(10);
    
    
    } while (!settledExit.canExit(error) && !velocitySettleExit.canExit(error-prev_error));


}

Odom testOdom;
Pose testPose(0,0,0);


Drive chassis(leftDrive, rightDrive, testPose, lateralPID, angularPID,testOdom);