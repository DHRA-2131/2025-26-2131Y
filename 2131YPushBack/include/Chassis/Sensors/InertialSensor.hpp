/**
 * @file InertialSensor.hpp
 * @author Ezra Jones (2131Y)
 * @brief Inertial Sensor Class
 * @version 2.0
 * @date 2025-09-22
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#pragma once

#include "pros/imu.hpp"
#include <ostream>

#include "Util/Positioning/Angle.hpp"

class InertialSensor : pros::Imu {
    public:
        /**
         * @brief Return angle of inertial sensor wrapped to 0-360 (0-2PI)
         * 
         * @return Angle 
         */
        Angle angle(); 
};

