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
        float m_wheelGearing;
        
    public:

        /**
         * @brief Construct a new Motor Encoder object
         * 
         * Attach an already existing motor group, add the radius and offset, and add the gear ratio
         * Gear Ratio is in Input/Output, for example, a 12:48 ratio would be a 12/48 or a gear ratio of 4.
         *
         * @param motors 
         * @param wheelRadius 
         * @param wheelOffset 
         */
        MotorEncoder(pros::MotorGroup& motors, float wheelRadius, float wheelOffset, float wheelGearing);

        /**
         * @brief Get the Position of the Motor Encoder in degrees
         * 
         * @return float 
         */
        float getPosition() override;

        /**
         * @brief Reset the Motor Encoder's Values
         * 
         */
        void reset() override;

};