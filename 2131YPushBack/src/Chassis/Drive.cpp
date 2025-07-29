#include "Chassis/Drive.hpp"

#include "Competition/RobotConfig.hpp"
#include "Utilities/Logging.hpp"
#include "Utilities/PID.hpp"
#include "Utilities/ExitConditions.hpp"
#include "Utilities/Parameters.hpp"
#include "Utilities/Positioning.hpp"
#include "Utilities/mathUtils.hpp"
#include "pros/screen.hpp"
#include <algorithm>




Drive::Drive(pros::MotorGroup& leftSideGroup, pros::MotorGroup& rightSideGroup, Pose& startingPose, PID& lateralPID, PID& angularPID) : 
leftSide(leftSideGroup), 
rightSide(rightSideGroup),
currentPose(startingPose),
m_lateralPID(lateralPID),
m_angularPID(angularPID)
{

}

void Drive::driveVoltage(double leftVoltage, double rightVoltage){

    /* Use move_voltage instead of move bc move goes from -127 to 127 instead of -12v to 12v */

    this->leftSide.move_voltage(leftVoltage*1000); // *1000 because it takes in millivolts
    this->rightSide.move_voltage(rightVoltage*1000);
   
}

void Drive::driveToPoint(Point point, drivingParameters drivingSettings){
    double distanceToPoint = 0;
    double prevDistanceToPoint = 0;

    double angleToPoint = 0;
    double lateralError = 0;

    double lateralOutput = 0;
    double angularOutput = 0;

    double prevLateralOutput = 0;
    double prevAngularOutput = 0;

    ExitCondition settleExit(drivingSettings.settleExitRange, drivingSettings.settleExitTime, 10);
    ExitCondition velocitySettleExit(drivingSettings.velocitySettleExitRange, drivingSettings.velocitySettleExitTime, 10);

    
    m_angularPID.reset();
    m_lateralPID.reset();

    

    // Async Movements
    if (!drivingSettings.waitForCompletion){
        drivingSettings.waitForCompletion = false;
        
        pros::Task asyncTask([=,this]{driveToPoint(point, drivingSettings);});
        return;
    }

   

    do {

        // Calculate Distance and Angle To
        distanceToPoint = currentPose.getDistanceTo(point);
        angleToPoint = currentPose.getAngleTo(point);

         
        // Calculate Lateral Error
        lateralError = distanceToPoint * cos(toRad(angleToPoint));

        // Angle based on Forward Movement
        if (!drivingSettings.forward) 
            angleToPoint = (angleToPoint < 0) ? angleToPoint + 180 : angleToPoint - 180;

        // Calculate Lateral PID
        lateralOutput = m_lateralPID.calculate(lateralError);


        // Prevent turning when close enough
        angularOutput = (distanceToPoint < drivingSettings.lockAngleDistance) ? 0 : m_angularPID.calculate(angleToPoint);

        angularOutput = constrainAccel(std::clamp(angularOutput, -drivingSettings.maxSpeed, drivingSettings.maxSpeed), prevAngularOutput, drivingSettings.maxAccel);
        
        // Might need to only constrain on decel for speed
        lateralOutput = constrainAccel(std::clamp<double>(lateralOutput, -drivingSettings.maxSpeed, drivingSettings.maxSpeed), prevLateralOutput, drivingSettings.maxAccel);

        // Checking Minimum Speed
        if (lateralOutput > 0) {
            if (lateralOutput < drivingSettings.minSpeed)
                lateralOutput = drivingSettings.minSpeed;
        }
        else if (lateralOutput > -drivingSettings.minSpeed) {
            lateralOutput = -drivingSettings.minSpeed;
        }

        // Set Previous Outputs
        prevLateralOutput = lateralOutput;
        prevAngularOutput = angularOutput;

        // lateralOutput = 314;
        // angularOutput = 0;

        //pros::screen::print(pros::E_TEXT_MEDIUM, 1, "Angle: %f", angularOutput);
        //pros::screen::print(pros::E_TEXT_MEDIUM, 2, "Lateral: %f", lateralOutput);
        log(logLocation::Drive, "Angular: %f, Lateral %f, GlobalX: %f, Distance: %f, Angle: %f, Velocity: %f, Settle %i, Vel Settle: %i", angularOutput, lateralOutput, currentPose.x, distanceToPoint,angleToPoint, distanceToPoint-prevDistanceToPoint, settleExit.canExit(distanceToPoint), velocitySettleExit.canExit(distanceToPoint-prevDistanceToPoint));

        // Move Motors
        this->leftSide.move(lateralOutput + angularOutput);
        this->rightSide.move(lateralOutput - angularOutput);
        
        pros::delay(10);
        
    } while(!settleExit.canExit(distanceToPoint) || !velocitySettleExit.canExit(distanceToPoint - prevDistanceToPoint));

    // Stop Driving
    if (drivingSettings.stopDriving){

        leftSide.set_brake_mode(pros::MotorBrake::brake);
        rightSide.set_brake_mode(pros::MotorBrake::brake);

        leftSide.brake();
        rightSide.brake();
    }

    log(logLocation::Drive, "Got Here!");

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

    if (!turningSettings.waitForCompletion){
        turningSettings.waitForCompletion = false;

        pros::Task asyncTask([=, this]{turnToAbsoluteHeading(targetHeading, turningSettings);});
        return;
    }

    do {

    //Prevent turning more than nessisary
    error = wrapAngle(targetHeading - currentPose.theta);
    
    double output = std::clamp(m_angularPID.calculate(error), -turningSettings.maxSpeed, turningSettings.maxSpeed);
    output = constrainAccel(output, prev_output, turningSettings.maxAccel);
    

    if (turningSettings.arc == arcDirection::arcToLeft) this->rightSide.move_voltage(output);
    else if (turningSettings.arc == arcDirection::arcToRight) this->leftSide.move_voltage(output);
    else {
        this->leftSide.move(-output);
        this->rightSide.move(output);
    }

    prev_error = error;
    prev_output = output;

    log(logLocation::Drive, "Output: %f, Settle %i", output, settledExit.canExit(error));
    pros::delay(10);
    
    
    } while (!settledExit.canExit(error) || !velocitySettleExit.canExit(error-prev_error));


}





Drive chassis(leftDrive, rightDrive, globalRobotPose, lateralPID, angularPID);