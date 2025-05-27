#pragma once

#include "pros/motor_group.hpp"

#include "Utilities/Odom.hpp"
#include "Utilities/Positioning.hpp"
#include "Utilities/PID.hpp"

class Drive
{
    public:

        pros::MotorGroup& leftSide;
        pros::MotorGroup& rightSide;


        Drive(pros::MotorGroup& leftSideGroup, pros::MotorGroup& rightSideGroup, Pose& startingPose, PID& lateralPID, PID& angularPID, Odom& driveOdom);

        void driveVoltage(double leftVoltage, double rightVoltage);
        void driveToPoint(Point point);
        void turnToPoint(Point point);

        void turnToAbsoluteHeading(double targetHeading);

        Pose currentPose;

    
    private:

        Odom& m_driveOdom;
        PID& m_lateralPID;
        PID& m_angularPID;

};


extern Drive chassis;