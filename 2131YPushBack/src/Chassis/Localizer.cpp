#include "Chassis/Localizer.hpp"


Localizer::Localizer(TrackingWheel& positionSensor, InertialSensor& inertialSensor, Pose robotPosition)
    : m_positionSensor(positionSensor), m_inertialSensor(inertialSensor), m_robotPosition(robotPosition), m_prevTime(0.0f)
{}


Pose Localizer::getRobotPosition() const
{
    return m_robotPosition;
}


void Localizer::setRobotPosition(Pose robotPosition)
{
    m_robotPosition = robotPosition;
}


void Localizer::update()
{

}
