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
#include "pros/motor_group.hpp"
#include "Eigen/Eigen"

class MotorEncoder : private AbstractEncoder
{
    private:
        pros::MotorGroup& m_motorSensor;
        Eigen::Vector3f m_motorState;

    public:

        /**
         * @brief Construct a new Abstract Encoder object
         * 
         */
        MotorEncoder(pros::MotorGroup& motorSensor, Eigen::Vector3f motorState);

        /**
         * @brief Get the Position value
         * 
         * @return float 
         */
        float getPosition() const override;

        /**
         * @brief Get the Velocity value
         * 
         * @return float 
         */
        float getVelocity() const override;
        
        /**
         * @brief Get the Acceleration value
         * 
         * @return float 
         */
        float getAcceleration() const override;

        /**
         * @brief Get the State object
         * 
         * @return Eigen::Vector3f
         */
        Eigen::Vector3f getState() const override;

        /**
         * @brief Get the Timestep value
         * 
         * @return float 
         */
        float getTimestep() const override;
        
        /**
         * @brief Update Motor Encoder Values
         * 
         */
        void update() override;

        /**
         * @brief Reset
         * 
         */
        void reset() override;
};