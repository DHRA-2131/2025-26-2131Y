/**
 * @file PIDController.hpp
 * @author Ezra Jones (2131Y)
 * @brief PID Movement Control
 * @version 0.1
 * @date 2025-10-16
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include "MotionControl/PIDController/PID.hpp"
#include "Chassis/Chassis.hpp"


class PIDController
{
    private:
        DriveBase& m_robotDrive;
        PID& m_lateralPID;
        PID& m_angularPID;

    public:

        /**
         * @brief Construct a new PIDController object
         * 
         * @param robotDrive 
         * @param lateralPID 
         * @param angularPID 
         */
        PIDController(DriveBase& robotDrive, PID& lateralPID, PID& angularPID);

        PIDController(const PIDController&) = delete;
        PIDController& operator=(const PIDController&) = delete;
        
        
};