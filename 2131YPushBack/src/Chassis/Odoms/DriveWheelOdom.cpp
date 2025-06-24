#include "DriveWheelOdom.hpp"
#include "Utilities/AbstractOdom.hpp"
#include "Utilities/Logging.hpp"
#include "Utilities/mathUtils.hpp"
#include "Competition/RobotConfig.hpp"
#include "pros/screen.hpp"

DriveWheelOdom::DriveWheelOdom(Pose& RobotPose, pros::IMU& Imu, pros::MotorGroup& Left, pros::MotorGroup& Right, double WheelOffset, double WheelDiameter) :
/*AbstractOdom(RobotPose, Imu),*/
m_currentPose(RobotPose),
m_imu(Imu),
m_leftMotors(Left),
m_rightMotors(Right),
m_wheelDiameter(WheelDiameter),
m_wheelOffset(WheelDiameter),
m_prevPose(0,0,0),

m_updateTask([=, this](){
  
    while(true){
        pros::screen::print(pros::E_TEXT_MEDIUM, 3, "It worked!");
        this->m_currentPose.theta = m_imu.get_heading();
  
        double angle = toRad(wrapAngle(m_currentPose.theta - m_prevPose.theta)); //Wrap it here and again becasue some stuff just uses straight angle
        double avgAngle = wrapAngle((m_currentPose.theta + m_prevPose.theta)/2, false); //Set wrapAngle to radians


        
        double avgRotation = (m_leftMotors.get_position()+m_rightMotors.get_position())/2;

        double deltaRotation = avgRotation - m_prevRotation;

        

        double distanceTraveled = deltaRotation*m_wheelDiameter/2;
        double radius = (distanceTraveled/angle);


        

        

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
        m_prevRotation = avgRotation;
        

       
        pros::delay(10);




    }
})
{}

DriveWheelOdom::~DriveWheelOdom(){
    m_updateTask.remove();
}

void DriveWheelOdom::startOdom(){}
void DriveWheelOdom::stopOdom(){}
void DriveWheelOdom::setPosition(Pose& newPose){}

DriveWheelOdom robotOdom(globalRobotPose, IMU, leftDrive, rightDrive, 8, 3.25);