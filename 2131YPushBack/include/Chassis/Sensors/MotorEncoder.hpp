/**
 * @file MotorEncoder.hpp
 * @author Ezra Jones (2131Y)
 * @brief Motor Encoder for Tracking Systems
 * @version 0.1
 * @date 2025-10-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include "Chassis/Sensors/AbstractEncoder.hpp"

class MotorEncoder : private AbstractEncoder
{
    public:

        /**
         * @brief Construct a new Abstract Encoder object
         * 
         */
        MotorEncoder() = default;

        /**
         * @brief Destroy the Abstract Encoder object
         * 
         */
        virtual ~AbstractEncoder() = default;

        /**
         * @brief Get the Position value
         * 
         * @return float 
         */
        virtual float getPosition() const = 0;

        /**
         * @brief Get the Velocity value
         * 
         * @return float 
         */
        virtual float getVelocity() const = 0;
        
        /**
         * @brief Get the Acceleration value
         * 
         * @return float 
         */
        virtual float getAcceleration() const = 0;

        /**
         * @brief Get the State object
         * 
         * @return Eigen::Vector3<float> 
         */
        virtual Eigen::Vector3<float> getState() const = 0;

        /**
         * @brief Get the Timestep value
         * 
         * @return float 
         */
        virtual float getTimestep() const = 0;
};