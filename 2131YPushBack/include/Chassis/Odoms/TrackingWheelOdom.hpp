#pragma once

#include "Utilities/AbstractOdom.hpp"
#include "pros/rotation.hpp"


class TrackingWheelOdom : public AbstractOdom 
{   
    public:

        TrackingWheelOdom(Pose& robotPose, pros::Rotation& VerticalTrackingWheel, pros::Rotation& HorizontalTrackingWheel, double VerticalWheelOffset, double HorizontalWheelOffset, double WheelDiameter, pros::IMU& Imu);

    private:
        pros::Rotation& m_verticalTrackingWheel;
        pros::Rotation& m_horizontalTrackingWheel;

        const double m_verticalWheelOffset;
        const double m_horizontalWheelOffset;
        const double m_wheelDiameter;

     

        pros::Task m_updateTask;

        double m_prevVerticalTrackingRotation;

        Pose m_prevPose;

};