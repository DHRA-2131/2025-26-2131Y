#pragma once

#include "pros/motor_group.hpp"


#include "Utilities/Positioning.hpp"
#include "Utilities/PID.hpp"

#include "Utilities/Parameters.hpp"

class Drive
{
    public:

        pros::MotorGroup& leftSide;
        pros::MotorGroup& rightSide;


        Drive(pros::MotorGroup& leftSideGroup, pros::MotorGroup& rightSideGroup, Pose& startingPose, PID& lateralPID, PID& angularPID);

        void driveVoltage(double leftVoltage, double rightVoltage);
        void driveToPoint(Point point, drivingParameters drivingSettings);
        void turnToPoint(Point point, turningParameters turningSettings);

        void turnToAbsoluteHeading(double targetHeading, turningParameters turningSettings);

        Pose currentPose;

    
    private:

        //No need for the odom if having the current pose
        //AbstractOdom& m_driveOdom;
        PID& m_lateralPID;
        PID& m_angularPID;

};


extern Drive chassis;