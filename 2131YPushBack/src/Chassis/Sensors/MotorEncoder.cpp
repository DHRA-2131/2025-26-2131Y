#include "Chassis/Sensors/MotorEncoder.hpp"
#include "Util/Constants.hpp"
#include "Util/MathFunctions.hpp"
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
    m_motorSensor.set_encoder_units_all(pros::E_MOTOR_ENCODER_DEGREES);
    m_motorState[0] = average<double>(m_motorSensor.get_position_all());
    m_motorState[1] = average<double>(m_motorSensor.get_actual_velocity_all()) * rpm_to_degpsec;
    m_motorState[2] = m_motorState[1] / (deltaTime * millis_to_sec);
}


void MotorEncoder::reset()
{
    m_motorState = {0.0f, 0.0f, 0.0f};
    m_motorSensor.tare_position_all(); // ? Is this the correct command for reset position/velocity;
}