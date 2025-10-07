/**
 * @file DriveBase.hpp
 * @author Ezra Jones (2131Y)
 * @brief Drive Base Movements
 * @version 2.0
 * @date 2025-09-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#pragma once

#include "pros/motor_group.hpp"

#include "Chassis/Odom.hpp"
#include "Util/MovementSettings.hpp"
#include "Util/PIDController.hpp"

class DriveBase
{
    private:

        enum class ControlMethods
        {
            TankDrive = 0,
            ArcadeDrive
        };

        pros::MotorGroup& m_rightDrive;
        pros::MotorGroup& m_leftDrive;

        Odometry& m_robotOdom;

        PIDController& m_lateralPID;
        PIDController& m_angularPID;

        bool m_inMotion;
        
        ControlMethods m_driveControl;
        int m_joystickDeadZone;


    public:

        /**
         * @brief Construct a new Drive Base object
         * 
         * @param rightDrive 
         * @param leftDrive 
         * @param robotOdom 
         * @param lateralPID 
         * @param angularPID 
         * @param inMotion 
         * @param driveControl 
         */
        DriveBase(pros::MotorGroup& rightDrive, pros::MotorGroup& leftDrive, Odometry& robotOdom, 
            PIDController& lateralPID, PIDController& angularPID, bool inMotion, 
            ControlMethods driveControl = ControlMethods::ArcadeDrive, int joystickDeadZone = 10);

        /**
         * @brief Manage Drive Control
         * 
         */
        void driveControl();

        /**
         * @brief Drive to a Point Location
         * 
         * @param targetPoint 
         * @param drivingParams 
         */
        void driveToPoint(Point& targetPoint, driveToPointSettings drivingParams = {});

        /**
         * @brief Turn to Point Location
         * 
         * @param targetPoint 
         * @param turnParams 
         */
        void turnToPoint(Point& targetPoint, turnToPointSettings turnParams = {});

        /**
         * @brief Turn to Heading
         * 
         * @param targetHeading 
         * @param turnParams 
         */
        void turnToHeading(float targetHeading, turnToHeadingSettings turnParams = {});

        /**
         * @brief Delay Until All Movements are Over
         * 
         */
        void delayUntilMovementsEnd() const;

};