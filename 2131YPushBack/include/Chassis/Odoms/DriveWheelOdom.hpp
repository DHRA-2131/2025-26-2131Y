#pragma once

#include "Utilities/Positioning.hpp"
#include "Utilities/AbstractOdom.hpp"
#include "pros/motor_group.hpp"
#include "pros/imu.hpp"

class DriveWheelOdom : public AbstractOdom{

    public:
        DriveWheelOdom(Pose& RobotPose,  pros::IMU& Imu, pros::MotorGroup& Left, pros::MotorGroup& Right,double WheelOffset,double WheelDiameter, double GearRatio);
        ~DriveWheelOdom();

        void startOdom() override;
        void stopOdom() override;

        void setPosition(Pose& newPose) override;

    private:
        
        Pose m_prevPose;
        pros::MotorGroup& m_leftMotors;
        pros::MotorGroup& m_rightMotors;

        const double m_wheelDiameter;
        const double m_wheelOffset;
        const double m_gearRatio;

        pros::Imu& m_imu;
        Pose& m_currentPose;


        

        double m_prevRotation;

        

};

//extern DriveWheelOdom robotOdom;