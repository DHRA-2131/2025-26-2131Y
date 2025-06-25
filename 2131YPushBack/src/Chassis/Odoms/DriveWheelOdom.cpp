#include "DriveWheelOdom.hpp"

#include "Utilities/logging.hpp"
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
        this->m_currentPose.theta = (m_imu.get_heading());
  
        double deltaAngle = 0;//toRad(wrapAngle(m_currentPose.theta - m_prevPose.theta)); //Wrap it here and again becasue some stuff just uses straight angle
        double avgAngle = 0;//toRad(((m_currentPose.theta + m_prevPose.theta)/2)); //Set wrapAngle to radians

        log(logLocation::Odom, "Angle %f, Avg Angle: %f", deltaAngle, avgAngle);


        
        double avgRotation = ((m_leftMotors.get_position()*0.75));

        double deltaRotation = (toRad((avgRotation - m_prevRotation)));

        log(logLocation::Odom, "Avg Rotation: %f, Delta Rotation: %f", avgRotation, deltaRotation);

        //log(logLocation::Odom, "Avg: %f, Prev %f, Delta %f, DeltaRotation(Rad): %f",avgRotation, m_prevRotation, avgRotation - m_prevRotation, deltaRotation);

        

        double distanceTraveled = deltaRotation/(m_wheelDiameter/2);

        //log(logLocation::Odom, "Distance Traveled: %f", distanceTraveled);
        

        //log(logLocation::Odom, "Distance Traveled: %f, Radius: %f",distanceTraveled, radius);


        

        

        if (!(deltaAngle == 0)){
            double radius = (distanceTraveled/deltaAngle)-WheelOffset;
            double linearDistance = 2*radius*sin(deltaAngle/2);
            log(logLocation::Odom, "Linear Distance %f", linearDistance);


            

            m_currentPose.x += linearDistance*cos(avgAngle);
            m_currentPose.y += linearDistance*sin(avgAngle);

        }
        else {
            
            m_currentPose.x += distanceTraveled*cos(toRad(m_currentPose.theta));
            m_currentPose.y += distanceTraveled*sin(toRad(m_currentPose.theta));
        }

        m_prevPose = m_currentPose;
        m_prevRotation = avgRotation;
    

        log(logLocation::Odom, "X: %f, Y: %f, Theta: %f", m_currentPose.x, m_currentPose.y, m_currentPose.theta);
        

       
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

//DriveWheelOdom robotOdom(globalRobotPose, IMU, leftDrive, rightDrive, 8, 3.25);