#pragma once

#include "pros/motor_group.hpp"


#include "Utilities/Positioning.hpp"
#include "Utilities/PID.hpp"

#include "Utilities/Parameters.hpp"

/**
 * @brief Construct a new Drivetrain
 * 
 * @param leftSideGroup
 * @param rightSideGroup
 * @param startingPose
 * @param lateralPID
 * @param angularPID
 *
 */

class Drive
{
    public:

        pros::MotorGroup& leftSide;
        pros::MotorGroup& rightSide;


        Drive(pros::MotorGroup& leftSideGroup, pros::MotorGroup& rightSideGroup, Pose& startingPose, PID& lateralPID, PID& angularPID);

        /**
         * @brief Set Drive Voltage
         * 
         * @param leftVoltage
         * @param rightVoltage
         */

        void driveVoltage(double leftVoltage, double rightVoltage);


        /**
         * @brief Drive to specified point
         * 
         * @param point
         * @param drivingSettings
         */

        void driveToPoint(Point point, drivingParameters drivingSettings = {});


        /**
         * @brief Turn to specified point
         *
         * @param point
         * @param turningSettings
         */

        void turnToPoint(Point point, turningParameters turningSettings = {});


        /**
         * @brief Turn to specified heading
         *
         * @param targetHeading
         * @param turningSettings
         */

        void turnToAbsoluteHeading(double targetHeading, turningParameters turningSettings = {});

        Pose currentPose;

    
    private:

        //No need for the odom if having the current pose
        //AbstractOdom& m_driveOdom;
        PID& m_lateralPID;
        PID& m_angularPID;

};


extern Drive chassis;