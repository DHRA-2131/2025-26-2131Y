#include "DriveWheelOdom.hpp"
#include "Utilities/AbstractOdom.hpp"
#include "Utilities/Logging.hpp"
#include "Utilities/mathUtils.hpp"
#include "Competition/RobotConfig.hpp"

DriveWheelOdom::DriveWheelOdom(Pose& RobotPose, pros::IMU& Imu, pros::MotorGroup& Left, pros::MotorGroup& Right, double WheelOffset, double WheelDiameter) :
/*AbstractOdom(RobotPose, Imu),*/
m_currentPose(RobotPose),
m_imu(Imu),
m_leftMotors(Left),
m_rightMotors(Right),
m_wheelDiameter(WheelDiameter),
m_wheelOffset(WheelDiameter),
m_prevPose(0,0,0),

updateTask([=, this](){
  
    while(true){
        
        //this->m_currentPose.theta = 5;//m_imu.get_heading();
        Pose m_currentPose(0,0,0);

        double x = m_imu.get_heading();
   
        //log(logLocation::Odom, "Got to here");

        
        
        double angle = wrapAngle(toRad(m_currentPose.theta - m_prevPose.theta));

        

        double avgRotation = (m_leftMotors.get_position()+m_rightMotors.get_position())/2;

        double distanceTraveled = toRad(avgRotation)*m_wheelDiameter/2;
        double radius = (distanceTraveled/angle)-m_wheelOffset;

        double avgAngle = wrapAngle(toRad((m_currentPose.theta + m_prevPose.theta)/2));

        if (!(angle == 0)){
            double linearDistance = 2*radius*sin(angle/2);

            m_currentPose.x += linearDistance*cos(avgAngle);
            m_currentPose.y += linearDistance*sin(avgAngle);

        }
        else {
            m_currentPose.x += distanceTraveled*cos(avgAngle);
            m_currentPose.y += distanceTraveled*sin(avgAngle);
        }

        m_prevPose = m_currentPose;




    }
})
{

}

void DriveWheelOdom::startOdom(){}
void DriveWheelOdom::stopOdom(){}
void DriveWheelOdom::setPosition(Pose& newPose){}