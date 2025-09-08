
#include "Chassis/Odoms/DriveWheelOdom.hpp"
#include "Competition/RobotConfig.hpp"
#include "Utilities/Positioning.hpp"
#include "Utilities/logging.hpp"
#include "Utilities/mathUtils.hpp"




DriveWheelOdom::DriveWheelOdom(Pose& RobotPose, pros::IMU& Imu, pros::MotorGroup& Left, pros::MotorGroup& Right, double WheelOffset, double WheelDiameter, double GearRatio) :
AbstractOdom(RobotPose, Imu, new pros::Task([=, this](){


    this->m_updateTask->suspend();

    
    log(logLocation::Odom, "(%f, %f, %f)", m_currentPose.getX(), m_currentPose.getY(), globalRobotPose.getTheta());
    log(logLocation::Odom, "(%f, %f, %f)", globalRobotPose.getX(), globalRobotPose.getY(), globalRobotPose.getTheta());

          

     

  
    while(true){
        this->m_currentPose.mutex->take();
        this->m_currentPose.theta = (m_imu.get_heading());
  
        double deltaAngle = toRad(wrapAngle(m_currentPose.theta-m_prevPose.theta));
        double avgAngle = toRad(((m_currentPose.theta+m_prevPose.theta)/2));

        
        this->m_currentPose.mutex->give();

        

      

        
        
        double avgRotation = ((m_leftMotors.get_position())/m_gearRatio);
        double deltaRotation = (toRad((avgRotation - m_prevRotation)));

        double distanceTraveled = deltaRotation/(m_wheelDiameter/2);

       
        if (!(fabs(deltaAngle) <= 0.05)){
            double radius = (distanceTraveled/deltaAngle)-m_wheelOffset;
            double linearDistance = 2*radius*sin(deltaAngle/2);

            log(logLocation::Odom, "Linear Distance %f", linearDistance);

            
            this->m_currentPose.mutex->take(); 
            this->m_currentPose.y += linearDistance*cos(avgAngle);
           
            this->m_currentPose.x += linearDistance*sin(avgAngle);
            this->m_currentPose.mutex->give();

            

             

        }
        else {

            
          
            this->m_currentPose.mutex->take();
            log(logLocation::Odom, "(%f, %f, %f)", m_currentPose.x, m_currentPose.y, globalRobotPose.theta);

            this->m_currentPose.y += distanceTraveled*cos(toRad(m_currentPose.theta));
        
            this->m_currentPose.x += distanceTraveled*sin(toRad(m_currentPose.theta));
            log(logLocation::Odom, "(%f, %f, %f)", m_currentPose.x, m_currentPose.y, globalRobotPose.theta);
            this->m_currentPose.mutex->give();

            
        }

        this->m_prevPose = this->m_currentPose;
        this->m_prevRotation = avgRotation;
        

       
        
       

        //log(logLocation::Odom, "X: %f, Y: %f, Theta: %f", m_currentPose.x, m_currentPose.y, m_currentPose.theta);
        

       
        pros::delay(10);
    }
})),


m_currentPose(RobotPose),
m_imu(Imu),
m_leftMotors(Left),
m_rightMotors(Right),
m_wheelDiameter(WheelDiameter),
m_wheelOffset(WheelDiameter),
m_gearRatio(GearRatio),
m_prevPose(0,0,0)
{}

DriveWheelOdom::~DriveWheelOdom(){
    delete this->m_updateTask;
}

void DriveWheelOdom::startOdom(){
    this->m_updateTask->resume();
}
void DriveWheelOdom::stopOdom(){
    this->m_updateTask->suspend();
}
void DriveWheelOdom::setPosition(Pose& newPose){
    this->m_currentPose.mutex->take();
    this->m_currentPose = newPose;
    this->m_currentPose.mutex->give();
    this->m_prevPose = newPose;
}

//DriveWheelOdom robotOdom(globalRobotPose, IMU, leftDrive, rightDrive, 8, 3.25);