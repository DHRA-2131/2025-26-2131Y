/**
 * @file InertialSensor.hpp
 * @author Ezra Jones (2131Y)
 * @brief 
 * @version 0.1
 * @date 2025-10-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include "pros/imu.hpp"
#include "Eigen/Eigen"


class InertialSensor : public pros::IMU
{
    private:
        
        // [x  , y  , theta  ]
        // [x' , y' , theta' ]
        // [x'', y'', theta'']
        Eigen::Matrix3f m_robotState;

        float m_prevTime;

    public:

        /**
         * @brief Construct a new InertialSensor object
         * 
         */
        InertialSensor(uint8_t port);

        /**
         * @brief Get the X State object
         * 
         * @return Eigen::Vector3f 
         */
        Eigen::Vector3f getStateX() const;

        /**
         * @brief Get the Y State object
         * 
         * @return Eigen::Vector3f 
         */
        Eigen::Vector3f getStateY() const;

        /**
         * @brief Get the Theta State object
         * 
         * @return Eigen::Vector3f 
         */
        Eigen::Vector3f getStateTheta() const;
        
        /**
         * @brief Get the State object
         * 
         * @return Eigen::Matrix3f 
         */
        Eigen::Matrix3f getState() const;

        /**
         * @brief Update Values
         * 
         */
        void update(Eigen::Matrix3f& stateUpdate);
};