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
#include <atomic>


class Angle
{
    private:

        

    public:

        std::atomic<float> theta;

        /**
         * @brief Construct a new Angle object
         * 
         * @param theta 
         */
        Angle(float theta, bool degrees = true);


        /**
         * @brief Set the Eigen Matrix object
         * 
         */
        void setEigenMatrix(Eigen::RowVector<float, 1>, bool degrees = true);

        /**
         * @brief Get the Eigen Matrix object
         * 
         * @return Eigen::RowVector<float, 1> 
         */
        Eigen::RowVector<float, 1> getEigenMatrix(bool degrees = true);


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

        explicit operator float() const {
        return theta;
        }


        float wrapAngle();

};

