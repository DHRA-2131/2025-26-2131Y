#include "Chassis/Sensors/MotorEncoder.hpp"
#include "Util/Constants.hpp"
#include "pros/motor_group.hpp"

#include "pros/rtos.hpp"


MotorEncoder::MotorEncoder(pros::MotorGroup& motorSensor, Eigen::Vector3f motorState)
    : m_motorSensor(motorSensor), m_motorState(motorState)
{}


float MotorEncoder::getPosition() const
{
    return m_motorState[0];
}


float MotorEncoder::getVelocity() const
{
    return m_motorState[1];
}


float MotorEncoder::getAcceleration() const
{
    return m_motorState[2];
}


Eigen::Vector3f MotorEncoder::getState() const
{
    return m_motorState;
}


void MotorEncoder::update(float deltaTime)
{
    float motorPosition = 0.0f;
    float motorVelocity = 0.0f;
    float motorAccel = 0.0f;
    for (int i = 0; i < m_motorSensor.get_port_all().size(); i++)
    {
        motorPosition += m_motorSensor.get_position(i);
        motorVelocity += m_motorSensor.get_actual_velocity(i);
        motorAccel += m_motorSensor.get_actual_velocity(i) / (deltaTime * millis_to_sec);
    }
    m_motorState[0] = 
}


void MotorEncoder::reset()
{

}