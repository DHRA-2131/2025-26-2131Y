/**
 * @file Localizer.hpp
 * @author Ezra Jones (2131Y)
 * @brief 
 * @version 0.1
 * @date 2025-10-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include "Chassis/TrackingWheel.hpp"
#include "Chassis/Sensors/InertialSensor.hpp"

class Localizer
{
    private:
        TrackingWheel& m_positionSensor;
        InertialSensor& m_inertialSensor;

        Eigen::RowVector3f m_robotPosition; 
        



};