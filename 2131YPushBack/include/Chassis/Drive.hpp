#pragma once

#include "pros/motor_group.hpp"

#include "Utilities/Odom.hpp"
#include "Utilities/Positioning.hpp"

class Drive
{
    public:

        pros::MotorGroup& leftSide;
        pros::MotorGroup& rightSide;


        Drive(pros::MotorGroup& leftSideGroup, pros::MotorGroup& rightSideGroup, Odom& driveOdom);

        void driveVoltage(double leftVoltage, double rightVoltage);
        void driveToPoint(Point point);
        void turnToPoint(Point point);

        void turnToAbsoluteHeading(double targetHeading);


    
    private:

        Odom& m_driveOdom;

};