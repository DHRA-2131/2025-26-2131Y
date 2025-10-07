#include "Chassis/Sensors/MotorEncoder.hpp"
#include "pros/motors.hpp"
#include "Util/MathFunctions.hpp"

MotorEncoder::MotorEncoder(pros::MotorGroup& motors, float wheelRadius, float wheelOffset, float wheelGearing)
    : AbstractEncoder(wheelRadius, wheelOffset), m_encoder(motors), m_wheelGearing(wheelGearing)
{}

float MotorEncoder::getPosition() const
{
    return static_cast<float>(average<double>({m_encoder.get_position(0), m_encoder.get_position(1), m_encoder.get_position(2)}));
}

void MotorEncoder::reset()
{
    m_encoder.tare_position();
}