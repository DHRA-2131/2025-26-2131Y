#pragma once

#include "Utilities/Positioning.hpp"
#include "pros/imu.hpp"

class AbstractOdom
{   
    public:

        //Adding in Constructor for AbstractOdom to initialize common data
        AbstractOdom(Pose& robotPose, pros::IMU& imu) : m_robotPose(robotPose), m_imu(imu) {};
        virtual Pose update();


    private:
        Pose& m_robotPose;
        pros::IMU& m_imu;
        
         
};

