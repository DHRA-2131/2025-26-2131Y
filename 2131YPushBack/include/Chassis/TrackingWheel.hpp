/**
 * @file TrackingWheel.hpp
 * @author Ezra Jones (2131Y)
 * @brief Tracking Wheel Handling
 * @version 2.0
 * @date 2025-10-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include "Chassis/Sensors/AbstractEncoder.hpp"

class TrackingWheel
{
    private:
        AbstractEncoder& m_encoder;
        const float m_wheelCircumference;
        const float m_gearRatio; 
        const Eigen::Vector2f m_wheelOffset;
        const bool m_horizontalWheel;
        const float m_encoderToInches;

    public:

        /**
         * @brief Construct a new Tracking Wheel object
         * 
         * @param encoder 
         * @param wheelCircumference 
         * @param gearRatio 
         * @param horizontalWheel 
         */
        TrackingWheel(AbstractEncoder& encoder, float wheelCircumference, float gearRatio, Eigen::Vector2f wheelOffset, bool horizontalWheel = true);

        /**
         * @brief Get the Position value
         * 
         * @return float 
         */
        float getPosition() const;

        /**
         * @brief Get the Velocity value
         * 
         * @return float 
         */
        float getVelocity() const;

        /**
         * @brief Get the Acceleration value
         * 
         * @return float 
         */
        float getAcceleration() const;

        /**
         * @brief Get the State object
         * 
         * @return Eigen::Vector3<float> 
         */
        Eigen::Vector3<float> getState() const;

        /**
         * @brief Get the Circumference value
         * 
         * @return float 
         */
        float getCircumference() const;

        /**
         * @brief Get the Gear Ratio value
         * 
         * @return float 
         */
        float getGearRatio() const;

        /**
         * @brief Get the Offset object
         * 
         * @return Eigen::Vector2f 
         */
        Eigen::Vector2f getOffset() const;

        /**
         * @brief Get the Horizontal Wheel value
         * 
         * @return true 
         * @return false 
         */
        bool getHorizontalWheel() const;

        /**
         * @brief Update Tracking Wheel
         * 
         * @param deltaTime 
         */
        void update(float deltaTime);

        /**
         * @brief Reset Tracking Wheel Values
         * 
         */
        void reset();
};