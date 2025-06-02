#pragma once

#include "Utilities/AbstractOdom.hpp"
#include "Utilities/Positioning.hpp"

#include "pros/motor_group.hpp"
#include "pros/imu.hpp"

class DriveWheelOdom : public AbstractOdom {

    public:
        DriveWheelOdom(Pose& robotPose, pros::MotorGroup& Left, pros::MotorGroup& Right,double WheelOffset,double WheelDiameter, pros::IMU& Imu);

    private:
        
        Pose m_prevPose;
        pros::MotorGroup& m_leftMotors;
        pros::MotorGroup& m_rightMotors;

        const double m_wheelDiameter;
        const double m_wheelOffset;


        pros::Task updateTask;

        double prevRotation;

        

};