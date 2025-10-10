/**
 * @file Chassis.hpp
 * @author Quinn Bracken
 * @brief Chassis that handles and controls moving motors
 * @version 0.1
 * @date 2025-10-08
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#pragma once

#include "pros/motor_group.hpp"
#include "pros/motors.h"

#include "MotionControl/MotionHandler.hpp"

#include "Position/Pose.hpp"
class DriveBase
 {
    private:
        DriveBase();
        pros::Task m_odomThread;
        pros::Task m_monitorThread;

        bool m_intialized = false;

        pros::MotorGroup* m_rightMotors;
        pros::MotorGroup* m_leftMotors;

        void* m_localizer;

    public:

        const MotionHandler* motionHandler;

        DriveBase(const DriveBase&) = delete;
        DriveBase& operator=(DriveBase const&) = delete;
        
       /**
        * @brief Init the Chassis
        * 
        * @param Right
        * @param Left
        * @param Localizer
        */
        void init(pros::MotorGroup* Right, pros::MotorGroup* Left, void* Localizer/* Replace void* to pointer to localizer object*/);
        
        /**
         * @brief Get the instance of the drivebase singleton
         * 
         * @return DriveBase* 
         */
        static DriveBase* instance();

        /**
         * @brief Set the Motors to specified "voltage" in units from -127 to 127
         * 
         * @param rightVoltage 
         * @param leftVoltage 
         */
        void setMotors(int rightVoltage, int leftVoltage);

        /**
         * @brief Set the Braking Mode
         * 
         * @param brakeMode 
         */
        void setBraking(pros::motor_brake_mode_e brakeMode);
        
        /**
         * @brief Get the Position
         * 
         * @return Pose 
         */
        Pose getPosition(); //Can get Matrix Values from Pose

        /**
         * @brief Set the Position
         * 
         * @param NewPose 
         */
        void setPosition(Pose NewPose);

        /**
         * @brief Set the Position object
         * 
         * @param NewVector 
         */
        void setPosition(Eigen::RowVector3f NewVector);

        enum class OdomState
        {
            Stop,
            Start
        };
        
        /**
         * @brief Set the Odom State
         * 
         * @param State 
         */
        void setOdom(OdomState State);
       

 };