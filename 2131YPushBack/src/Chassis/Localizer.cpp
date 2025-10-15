#include "Chassis/Localizer.hpp"


Localizer::Localizer(TrackingWheel& positionSensor, InertialSensor& inertialSensor, Pose robotPosition)
    : m_positionSensor(positionSensor), m_inertialSensor(inertialSensor), m_robotPosition(robotPosition), m_prevTime(pros::millis())
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
    float deltaTime = pros::millis() - m_prevTime;
    m_prevTime = deltaTime;
    m_positionSensor.update();
    m_inertialSensor.update(deltaTime);
}
