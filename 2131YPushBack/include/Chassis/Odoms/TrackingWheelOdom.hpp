#pragma once

#include "Utilities/AbstractOdom.hpp"
#include "pros/rotation.hpp"


class TrackingWheelOdom : public AbstractOdom 
{   
    public:

        TrackingWheelOdom(Pose& robotPose, pros::Rotation& VerticalTrackingWheel,double VerticalWheelOffset, double WheelDiameter, pros::IMU& Imu);
        ~TrackingWheelOdom();

        void startOdom() override;
        void stopOdom() override;
        void setPosition(Pose&) override;

    private:
        pros::Rotation& m_verticalTrackingWheel;

        const double m_verticalWheelOffset;
    
        const double m_wheelDiameter;

     

        pros::Task m_updateTask;

        double m_prevVerticalTrackingRotation;

        Pose m_prevPose;

};