/**
 * @file Odom.hpp
 * @author Ezra Jones (2131Y)
 * @brief Odometry Class
 * @version 2.0
 * @date 2025-09-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#pragma once

#include "Chassis/Sensors/AbstractEncoder.hpp"
#include "Chassis/Sensors/InertialSensor.hpp"
#include "Util/Positioning/Pose.hpp"


class Odometry
{
    private:
        Pose m_robotPosition;
        AbstractEncoder& m_encoder;
        InertialSensor& m_inertial;

        pros::Task m_calculatePosition;

    public:

        /**
         * @brief Construct a new Odometry object
         * 
         * @param robotPosition 
         * @param encoder 
         * @param inertial 
         */
        Odometry(Pose robotPosition, AbstractEncoder& encoder, InertialSensor& inertial);

        /**
         * @brief Get the Position object
         * 
         * @return Pose 
         */
        Pose getPosition() const;

        /**
         * @brief Set the Position object
         * 
         * @param newPosition 
         */
        void setPosition(Pose& newPosition);

        /**
         * @brief Get the Calculate Position object
         * 
         * @return pros::Task 
         */
        pros::Task getCalculatePosition() const;

};