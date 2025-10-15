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
#include "Util/Position/Pose.hpp"

class Localizer
{
    private:
        TrackingWheel& m_positionSensor;
        InertialSensor& m_inertialSensor;

        Pose m_robotPosition;

        float m_prevTime;
        float m_prevDistance;
        Angle m_prevHeading;
        

    public:

        /**
         * @brief Construct a new Localizer object
         * 
         * @param positionSensor 
         * @param inertialSensor 
         * @param robotPosition 
         */
        Localizer(TrackingWheel& positionSensor, InertialSensor& inertialSensor, Pose robotPosition);

        /**
         * @brief Get the Robot Position object
         * 
         * @return Pose 
         */
        Pose getRobotPosition() const;

        /**
         * @brief Set the Robot Position object
         * 
         */
        void setRobotPosition(Pose robotPosition);

        /**
         * @brief Update the Localizer
         * 
         */
        void update();
};