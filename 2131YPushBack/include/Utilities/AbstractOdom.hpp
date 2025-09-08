#pragma once

#include "Utilities/Positioning.hpp"
#include "pros/imu.hpp"
#include "pros/rtos.hpp"


class AbstractOdom
{   
    public:

        /**
         * @brief Abstract Odometry class constructor
         *
         * @param robotPose
         * @param imu
         *
         */
        AbstractOdom(Pose& RobotPose, pros::IMU& imu, pros::Task* UpdateTask) : m_currentPose(RobotPose), m_imu(imu), m_updateTask(UpdateTask){};
        
        virtual void startOdom() = 0; //Making it pure virtual
        virtual void stopOdom() = 0;

        virtual void setPosition(Pose& newPose) = 0;

        void resetPosition(){m_currentPose.mutex->lock(); m_currentPose.x = 0; m_currentPose.y = 0; m_currentPose.mutex->give();}

      


    protected: //Not private so child classes can access

        
        Pose& m_currentPose;

        pros::IMU& m_imu;

        pros::Task* m_updateTask;

       

        
        
         
};

