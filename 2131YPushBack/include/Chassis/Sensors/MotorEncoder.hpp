/**
 * @file MotorEncoder.hpp
 * @author Ezra Jones (2131Y)
 * @brief Motor Encoder Child Class
 * @version 2.0
 * @date 2025-09-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#pragma once

#include "Chassis/Sensors/AbstractEncoder.hpp"
#include "pros/motor_group.hpp"

class MotorEncoder : private AbstractEncoder
{
    private:

        pros::MotorGroup& m_encoder;
        
    public:

        /**
         * @brief Construct a new Motor Encoder object
         * 
         */
        MotorEncoder(float wheelRadius, float wheelOffset);

        /**
         * @brief Get the Position of the Motor Encoder in degrees
         * 
         * @return float 
         */
        virtual float getPosition() const = 0;

        /**
         * @brief Reset the Motor Encoder's Values
         * 
         */
        virtual void reset() = 0;

};