#pragma once

#include "Utilities/Positioning.hpp"
#include "pros/imu.hpp"

class AbstractOdom
{   
    public:

        //Adding in Constructor for AbstractOdom to initialize common data
        AbstractOdom(Pose& robotPose, pros::IMU& imu) : m_currentPose(robotPose), m_imu(imu){};
        virtual void startOdom() = 0; //Making it pure virtual
        virtual void stopOdom() = 0;

        virtual void setPosition(Pose& newPose) = 0;


    protected: //Not private so child classes can access
        Pose& m_currentPose;
        pros::IMU& m_imu;

       

        
        
         
};

