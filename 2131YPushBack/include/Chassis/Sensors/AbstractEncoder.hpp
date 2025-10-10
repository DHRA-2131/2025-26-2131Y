/**
 * @file AbstractEncoder.hpp
 * @author Ezra Jones
 * @brief Abstract Encoder for Tracking Systems
 * @version 2.0
 * @date 2025-10-08
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#pragma once


#include "Eigen/Eigen"


class AbstractEncoder
{
    public:

        /**
         * @brief Construct a new Abstract Encoder object
         * 
         */
        AbstractEncoder() = default;

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
         * @return Eigen::Vector3f
         */
        virtual Eigen::Vector3f getState() const = 0;

        /**
         * @brief Get the Timestep value
         * 
         * @return float 
         */
        virtual float getTimestep() const = 0;

        /**
         * @brief Update Encoder Values
         * 
         */
        virtual void update() = 0;

        /**
         * @brief Reset Encoder Values
         * 
         */
        virtual void reset() = 0;
};
