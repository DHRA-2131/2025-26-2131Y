#include "Chassis/Localizer.hpp"

#include "Util/MathFunctions.hpp"


Localizer::Localizer(TrackingWheel& positionSensor, InertialSensor& inertialSensor, Pose robotPosition)
    : m_positionSensor(positionSensor), m_inertialSensor(inertialSensor), m_robotPosition(robotPosition), m_prevTime(pros::millis()), m_prevDistance(0.0f), m_prevHeading(0.0f)
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
    m_prevTime = pros::millis();
    m_positionSensor.update(deltaTime);
    m_inertialSensor.update(deltaTime);

    float deltaDistance = m_positionSensor.getPosition() - m_prevDistance;
    Angle deltaTheta = Angle(m_inertialSensor.getStateTheta()[0]) - m_prevHeading;
    //deltaTheta.wrapAngle();
    
    
    if (!(deltaTheta.getTheta() == 0.0f))
    {
        // Calculate the Tracking Radius
        float trackingRadius = (deltaDistance / deltaTheta.getTheta(false));

        // Linear Distance Calculation
        float distance = 2 * trackingRadius * sin((deltaTheta.getTheta(false)) / 2);

        // Calculate Average Angle
        float avgTheta = average<float>({m_prevHeading.getTheta(), m_inertialSensor.getStateTheta()[0]});

        // Calculate Position Change Off Of Drive Base
        m_robotPosition.x += distance * cos(avgTheta);
        m_robotPosition.y += distance * sin(avgTheta);
    }
    else 
    {
        // Calculate Position Change Off Of Drive Base
        m_robotPosition.x += deltaDistance * cos(m_robotPosition.theta.getTheta(false));
        m_robotPosition.y += deltaDistance * sin(m_robotPosition.theta.getTheta(false));
    }

    m_prevDistance = m_positionSensor.getPosition();
    m_prevHeading = m_inertialSensor.getStateTheta()[0];
}
