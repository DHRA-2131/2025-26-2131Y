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

#include "Point.hpp"
#include "Angle.hpp"

#include "Eigen/Eigen"


#include <cmath>


class Pose : private Point
{


    public:

        Angle theta;

        /**
         * @brief Construct a new Pose object
         * 
         * @param x 
         * @param y 
         * @param theta 
         */
        Pose(float x, float y, Angle theta);
        Pose(const Pose& other);

        /**
         * @brief Calculate the Angle to Another Point
         * 
         * @param otherPoint 
         * @return float 
         */
        float angleToPoint(Point& otherPoint) const;

        void set(float x, float y, float theta);
        /**
         * @brief Set the Eigen Matrix Version
         * 
         */
        void setEigenMatrix(Eigen::RowVector3f);

        /**
         * @brief Get the Eigen Matrix Version
         * 
         * @return Eigen::RowVector3f 
         */
        Eigen::RowVector3f getEigenMatrix();



        friend std::ostream& operator<<(std::ostream& os, const Pose& printPose);
};

std::ostream& operator<<(std::ostream& os, const Pose& printPose);