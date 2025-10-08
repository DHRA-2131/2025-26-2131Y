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

#include "Eigen/Eigen"
#include <ostream>


class Angle
{
    private:

        float m_theta;

    public:

        /**
         * @brief Construct a new Angle object
         * 
         * @param theta 
         */
        Angle(float theta, bool degrees = true);

        /**
         * @brief Get Theta Value
         * 
         * @return float 
         */
        float getTheta(bool degrees = true) const;

        /**
         * @brief Set Theta Value
         * 
         * @param theta 
         */
        void setTheta(float theta, bool degrees = true);

        /**
         * @brief Set the Eigen Matrix object
         * 
         */
        void setEigenMatrix(Eigen::RowVector<float, 1>);

        /**
         * @brief Get the Eigen Matrix object
         * 
         * @return Eigen::RowVector<float, 1> 
         */
        Eigen::RowVector<float, 1> getEigenMatrix();

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