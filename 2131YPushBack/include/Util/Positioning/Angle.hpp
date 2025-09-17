/**
 * @file Angle.hpp
 * @author Ezra Jones
 * @brief Angle Class for Positioning
 * @version 2.0
 * @date 2025-09-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#pragma once

#include <iostream>


class Angle
{
    private:

        float m_theta;
        bool m_degrees;


        /**
         * @brief Construct a new Angle object
         * 
         * @param theta 
         * @param degrees 
         */
        Angle(float theta, bool degrees = false);

        /**
         * @brief Get Theta Value
         * 
         * @return float 
         */
        float getTheta() const;

        /**
         * @brief Get Degrees Value
         * 
         * @return true 
         * @return false 
         */
        bool getDegrees() const;

        /**
         * @brief Set Theta Value
         * 
         * @param theta 
         */
        void setTheta(float theta);

        /**
         * @brief Set Degrees Value
         * 
         * @param degrees
         */
        void setDegrees(bool degrees);

        /**
         * @brief Add Two Angles Together
         * 
         * @param otherAngle 
         * @return Angle 
         */
        Angle add(Angle& otherAngle) const;

        /**
         * @brief Subtract one Angle from Another
         * 
         * @param otherAngle 
         * @return Angle 
         */
        Angle subtract(Angle& otherAngle) const;

        /**
         * @brief Multiply a Angle by a Scalar
         * 
         * @param scalar 
         * @return Angle 
         */
        Angle multiply(float& scalar) const;

        /**
         * @brief Divide a Angle by a Scalar
         * 
         * @param scalar 
         * @return Angle 
         */
        Angle divide(float& scalar) const;

        /**
         * @brief Add Two Angles Together
         * 
         * @param otherAngle 
         * @return Angle 
         */
        Angle operator+(Angle& otherAngle) const;

        /**
         * @brief Subtract one Angle from Another
         * 
         * @param otherAngle 
         * @return Angle 
         */
        Angle operator-(Angle& otherAngle) const;

        /**
         * @brief Multiply a Angle by a Scalar
         * 
         * @param scalar 
         * @return Angle 
         */
        Angle operator*(float& scalar) const;

        /**
         * @brief Divide a Angle by a Scalar
         * 
         * @param scalar 
         * @return Angle 
         */
        Angle operator/(float& scalar) const;

        float wrapAngle();

        friend std::ostream& operator<<(std::ostream& os, const Angle& printAngle);

};

std::ostream& operator<<(std::ostream& os, const Angle& printAngle);

