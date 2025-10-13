/**
 * @file Localizer.hpp
 * @author Ezra Jones (2131Y)
 * @brief 
 * @version 0.1
 * @date 2025-10-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once

#include "Chassis/TrackingWheel.hpp"
#include "Chassis/Sensors/InertialSensor.hpp"

class Localizer
{
    private:
        TrackingWheel& m_positionSensor;
        InertialSensor& m_inertialSensor;

        Eigen::RowVector3f m_robotPosition;

        // [1, dt, dt^2/2]
        // [0, 1 , dt    ]
        // [0, 0 , 1     ]
        Eigen::Matrix3f m_stateUpdate;
        Eigen::Rotation2D<float> m_rotationMatrix;

        float m_prevTime;
        

    public:

        /**
         * @brief Construct a new Localizer object
         * 
         * @param positionSensor 
         * @param inertialSensor 
         * @param robotPosition 
         */
        Localizer(TrackingWheel& positionSensor, InertialSensor& inertialSensor, Eigen::RowVector3f robotPosition);

        /**
         * @brief Get the Robot Position object
         * 
         * @return Eigen::Vector3f 
         */
        Eigen::Vector3f getRobotPosition() const;

        /**
         * @brief Set the Robot Position object
         * 
         * @return Eigen::Vector3f 
         */
        Eigen::Vector3f setRobotPosition();

        /**
         * @brief Update the Localizer
         * 
         */
        void update();
};