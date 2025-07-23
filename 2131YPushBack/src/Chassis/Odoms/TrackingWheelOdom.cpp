#include "Chassis/Odoms/TrackingWheelOdom.hpp"
#include "Utilities/AbstractOdom.hpp"
#include "Utilities/mathUtils.hpp"
#include <cmath>
#include "Utilities/Logging.hpp"
#include "pros/rotation.hpp"
#include "pros/rtos.h"


TrackingWheelOdom::TrackingWheelOdom(Pose& robotPose, pros::Rotation& VerticalTrackingWheel,  double VerticalWheelOffset, pros::Rotation& HorizontalTrackingWheel, double HorizontalWheelOffset, double WheelDiameter, pros::IMU& Imu) :
AbstractOdom(robotPose, Imu),
m_verticalTrackingWheel(VerticalTrackingWheel),
m_horizontalTrackingWheel(HorizontalTrackingWheel),

m_verticalWheelOffset(VerticalWheelOffset),
m_horizontalWheelOffset(HorizontalWheelOffset),
m_wheelDiameter(WheelDiameter),

m_prevPose(0,0,0),
m_updateTask([=,this]{

    //Why suspend this task before starting it?
    m_verticalTrackingWheel.set_position(0);
    m_horizontalTrackingWheel.set_position(0);

    while(1){

    this->m_currentPose.theta = m_imu.get_heading();
    double deltaAngle = toRad(wrapAngle(m_currentPose.theta - m_prevPose.theta)); //Fix to -180 to 180
    double avgAngle = toRad(((m_currentPose.theta + m_prevPose.theta)/2));

    //Convert to float to keep precision
    double currentRotation = ((float)m_verticalTrackingWheel.get_position()/100);
    double deltaRotation = (toRad((currentRotation - m_prevVerticalTrackingRotation)));

    double distanceTraveled = deltaRotation/(m_wheelDiameter/2);

    if (!(fabs(deltaAngle) <= 0.05)){
            double radius = (distanceTraveled/deltaAngle)-m_verticalWheelOffset;
            double linearDistance = 2*radius*sin(deltaAngle/2);
            //log(logLocation::Odom, "Linear Distance %f", linearDistance);


            

            m_currentPose.x += linearDistance*cos(avgAngle);
            m_currentPose.y += linearDistance*sin(avgAngle);

        }
    else {
        
        m_currentPose.x += distanceTraveled*cos(toRad(m_currentPose.theta));
        m_currentPose.y += distanceTraveled*sin(toRad(m_currentPose.theta));
    }

     m_prevVerticalTrackingRotation = currentRotation;

    /******************************/
    /* Horizontal Wheel           */
    /******************************/
    
    //Convert to float to keep precision
    currentRotation = ((float)m_horizontalTrackingWheel.get_position()/100);
    deltaRotation = (toRad((currentRotation - m_prevHorizontalTrackingRotation)));

    distanceTraveled = deltaRotation/(m_wheelDiameter/2);

    //log(logLocation::Odom, "Tick Count: %i, Current Rot: %f, Delta Rot %f, Distance %f", m_horizontalTrackingWheel.get_position(), currentRotation, deltaRotation, distanceTraveled);

    if (!(fabs(deltaAngle) <= 0.05)){

            //log(logLocation::Odom, "Delta Angle Threshold reached!");
            double radius = (distanceTraveled/deltaAngle)-m_horizontalWheelOffset;
            double linearDistance = 2*radius*sin(deltaAngle/2);

            //log(logLocation::Odom, "Radius: %f, Distance: %f", radius, linearDistance);
            //log(logLocation::Odom, "Linear Distance %f", linearDistance);


            

            m_currentPose.y += linearDistance*cos(avgAngle);
            m_currentPose.x += linearDistance*sin(avgAngle);

        }
    else {
        
        m_currentPose.y += distanceTraveled*cos(toRad(m_currentPose.theta));
        m_currentPose.x += distanceTraveled*sin(toRad(m_currentPose.theta));
    }


    m_prevPose = m_currentPose;
    m_prevHorizontalTrackingRotation = currentRotation;

   
    //log(logLocation::Odom, "X: %f, Y: %f, Theta: %f, Rotation: %i", m_currentPose.x, m_currentPose.y, m_currentPose.theta,   m_verticalTrackingWheel.get_position());

    pros::delay(10);
    

}




    
    
   
}, TASK_PRIORITY_MAX)
{}


TrackingWheelOdom::~TrackingWheelOdom(){
    m_updateTask.remove();
}

void TrackingWheelOdom::startOdom(){};
void TrackingWheelOdom::stopOdom(){};
void TrackingWheelOdom::setPosition(Pose &){};



