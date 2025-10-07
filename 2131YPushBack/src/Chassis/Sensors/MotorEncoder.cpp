#include "Chassis/Sensors/MotorEncoder.hpp"

MotorEncoder::MotorEncoder(pros::MotorGroup& motors, float wheelRadius, float wheelOffset, float wheelGearing)
    : AbstractEncoder(wheelRadius, wheelOffset), m_encoder(motors), m_wheelGearing(wheelGearing)
{}

void MotorEncoder::reset()
{
    m_encoder.tare_position();
}

float MotorEncoder::getPosition() const
{
    return 0;
}

