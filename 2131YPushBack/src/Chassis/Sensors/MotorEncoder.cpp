#include "Chassis/Sensors/MotorEncoder.hpp"


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

/**
 * @brief Update Motor Encoder Values
 * 
 */
void update() override;

/**
 * @brief Reset
 * 
 */
void reset() override;