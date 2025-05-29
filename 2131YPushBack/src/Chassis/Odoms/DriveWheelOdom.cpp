#include "DriveWheelOdom.hpp"
#include "Utilities/AbstractOdom.hpp"
#include "Utilities/mathUtils.hpp"

DriveWheelOdom::DriveWheelOdom(Pose& robotPose, pros::MotorGroup& Left, pros::MotorGroup& Right, double WheelOffset, double WheelDiameter, pros::IMU& Imu) :
m_leftMotors(Left),
m_rightMotors(Right),
m_wheelDiameter(WheelDiameter),
m_wheelOffset(WheelDiameter),
m_prevPose(0,0,0),
AbstractOdom(robotPose, Imu),
updateTask([this]{
    
    while(1){
        
        m_currentPose.theta = m_imu.get_heading();
        double angle = wrapAngle(toRad(m_currentPose.theta - m_prevPose.theta));

        double avgRotation = (m_leftMotors.get_position()+m_rightMotors.get_position())/2;

        double distanceTraveled = toRad(avgRotation)*m_wheelDiameter/2;
        double radius = (distanceTraveled/angle)-m_wheelOffset;

        if (!(angle == 0)){
            double linearDistance = 2*radius*sin(angle/2);

            m_currentPose.x += linearDistance*cos(toRad(m_currentPose.theta));
            m_currentPose.y += linearDistance*sin(toRad(m_currentPose.theta));

        }
        else {
            m_currentPose.x += distanceTraveled*cos(toRad(m_currentPose.theta));
            m_currentPose.y += distanceTraveled*sin(toRad(m_currentPose.theta));
        }

        m_prevPose = m_currentPose;




    }
})
{}