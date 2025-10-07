/**
 * @file Pose.hpp
 * @author Ezra Jones (2131Y)
 * @brief Pose Class for Positioning
 * @version 2.0
 * @date 2025-09-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include "Util/Positioning/Point.hpp"
#include "Util/Positioning/Angle.hpp"
#include <cmath>


class Pose : private Point
{
    private:
        Angle m_theta;

    public:

        /**
         * @brief Construct a new Pose object
         * 
         * @param x 
         * @param y 
         * @param theta 
         */
        Pose(float x, float y, Angle theta);

        /**
         * @brief Get Theta Value
         * 
         * @return Angle 
         */
        Angle getTheta() const;

        /**
         * @brief Set Theta Value
         * 
         * @param theta 
         */
        void setTheta(Angle& theta);

        /**
         * @brief Calculate the Angle to Another Point
         * 
         * @param otherPoint 
         * @return float 
         */
        float angleToPoint(Point& otherPoint) const;


        friend std::ostream& operator<<(std::ostream& os, const Pose& printPose);
};

std::ostream& operator<<(std::ostream& os, const Pose& printPose);