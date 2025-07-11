#pragma once

#include "Utilities/AbstractOdom.hpp"
#include "pros/rotation.hpp"


class TrackingWheelOdom : public AbstractOdom 
{   
    public:

        TrackingWheelOdom(Pose& robotPose, pros::Rotation& VerticalTrackingWheel,double VerticalWheelOffset, pros::Rotation& HorizontalTrackingWheel, double HorizontalWheelOffset, double WheelDiameter, pros::IMU& Imu);
        ~TrackingWheelOdom();

        void startOdom() override;
        void stopOdom() override;
        void setPosition(Pose&) override;

    private:
        pros::Rotation& m_verticalTrackingWheel;
        pros::Rotation& m_horizontalTrackingWheel;


        const double m_verticalWheelOffset;
        const double m_horizontalWheelOffset;

        const double m_wheelDiameter;

     

        pros::Task m_updateTask;

        double m_prevVerticalTrackingRotation;
        double m_prevHorizontalTrackingRotation;

        Pose m_prevPose;

};