
#include "Chassis/Odoms/DriveWheelOdom.hpp"
#include "Utilities/logging.hpp"
#include "Utilities/mathUtils.hpp"
#include "Competition/RobotConfig.hpp"
#include "pros/screen.hpp"

DriveWheelOdom::DriveWheelOdom(Pose& RobotPose, pros::IMU& Imu, pros::MotorGroup& Left, pros::MotorGroup& Right, double WheelOffset, double WheelDiameter, double GearRatio) :
/*AbstractOdom(RobotPose, Imu),*/
m_currentPose(RobotPose),
m_imu(Imu),
m_leftMotors(Left),
m_rightMotors(Right),
m_wheelDiameter(WheelDiameter),
m_wheelOffset(WheelDiameter),
m_gearRatio(GearRatio),
m_prevPose(0,0,0),

m_updateTask([=, this](){

    this->m_updateTask.suspend();
  
    while(true){
        pros::screen::print(pros::E_TEXT_MEDIUM, 3, "It worked!");
        this->m_currentPose.theta = (m_imu.get_heading());
  
        double deltaAngle = toRad(wrapAngle(m_currentPose.theta-m_prevPose.theta));
        double avgAngle = toRad(((m_currentPose.theta+m_prevPose.theta)/2));//toRad(((m_currentPose.theta + m_prevPose.theta)/2)); //Set wrapAngle to radians


        //log(logLocation::Odom, "Angle %f, Avg Angle: %f", deltaAngle, avgAngle);


        
        double avgRotation = ((m_leftMotors.get_position())/m_gearRatio);

        double deltaRotation = (toRad((avgRotation - m_prevRotation)));

        //log(logLocation::Odom, "Avg Rotation: %f, Delta Rotation: %f", avgRotation, deltaRotation);

        //log(logLocation::Odom, "Avg: %f, Prev %f, Delta %f, DeltaRotation(Rad): %f",avgRotation, m_prevRotation, avgRotation - m_prevRotation, deltaRotation);

        

        double distanceTraveled = deltaRotation/(m_wheelDiameter/2);

        //log(logLocation::Odom, "Distance Traveled: %f", distanceTraveled);
        

        //log(logLocation::Odom, "Distance Traveled: %f, Radius: %f",distanceTraveled, radius);





        if (!(fabs(deltaAngle) <= 0.05)){
            double radius = (distanceTraveled/deltaAngle)-m_wheelOffset;
            double linearDistance = 2*radius*sin(deltaAngle/2);
            //log(logLocation::Odom, "Linear Distance %f", linearDistance);


            

            this->m_currentPose.y += linearDistance*cos(avgAngle);
            this->m_currentPose.x += linearDistance*sin(avgAngle);

        }
        else {
            
            this->m_currentPose.y += distanceTraveled*cos(toRad(m_currentPose.theta));
            this->m_currentPose.x += distanceTraveled*sin(toRad(m_currentPose.theta));
        }

        this->m_prevPose = this->m_currentPose;
        this->m_prevRotation = avgRotation;
    

        //log(logLocation::Odom, "X: %f, Y: %f, Theta: %f", m_currentPose.x, m_currentPose.y, m_currentPose.theta);
        

       
        pros::delay(10);




    }
})
{}

DriveWheelOdom::~DriveWheelOdom(){
    this->m_updateTask.remove();
}

void DriveWheelOdom::startOdom(){
    this->m_updateTask.resume();
}
void DriveWheelOdom::stopOdom(){
    this->m_updateTask.suspend();
}
void DriveWheelOdom::setPosition(Pose& newPose){
    this->m_currentPose = newPose;
    this->m_prevPose = newPose;
}

//DriveWheelOdom robotOdom(globalRobotPose, IMU, leftDrive, rightDrive, 8, 3.25);