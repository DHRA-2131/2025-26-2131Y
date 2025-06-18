#include "Chassis/Odoms/TrackingWheelOdom.hpp"
#include "Utilities/AbstractOdom.hpp"
#include "Utilities/mathUtils.hpp"
#include <cmath>


TrackingWheelOdom::TrackingWheelOdom(Pose& robotPose, pros::Rotation& VerticalTrackingWheel,  double VerticalWheelOffset, double WheelDiameter, pros::IMU& Imu) :
AbstractOdom(robotPose, Imu),
m_verticalTrackingWheel(VerticalTrackingWheel),

m_verticalWheelOffset(VerticalWheelOffset),
m_wheelDiameter(WheelDiameter),

m_prevPose(0,0,0),
m_updateTask([this]{

    //Why suspend this task before starting it?

    while(1){

    m_currentPose.theta = m_imu.get_heading();
    double angle = toRad(wrapAngle(m_currentPose.theta - m_prevPose.theta)); //Fix to -180 to 180
    

    //Calculate Delta then convert to inches traveled
    double verticalTrackingWheelArc = toRad((m_verticalTrackingWheel.get_position() - m_prevVerticalTrackingRotation))*m_wheelDiameter/2;


    double robotVerticalRadius = (verticalTrackingWheelArc/angle + m_verticalWheelOffset);
    
    double avgAngle = wrapAngle(toRad((m_currentPose.theta + m_prevPose.theta)/2));

    if (!(angle == 0)){
        double linearDistance = 2 * robotVerticalRadius * sin(angle/2);

        
        m_currentPose.x += linearDistance*cos(avgAngle);
        m_currentPose.y += linearDistance*sin(avgAngle);

    }

    else {
        double distance = m_verticalTrackingWheel.get_position() - m_prevVerticalTrackingRotation;
        m_currentPose.x += distance*cos(avgAngle);
        m_currentPose.y += distance*sin(avgAngle);
    }

    m_prevPose = m_currentPose;

}




    
    
   
})
{}




