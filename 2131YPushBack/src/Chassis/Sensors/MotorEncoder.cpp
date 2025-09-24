#include "Chassis/Sensors/MotorEncoder.hpp"

MotorEncoder(pros::MotorGroup& motors, float wheelRadius, float wheelOffset, float wheelGearing)
    : AbstractEncoder(wheelRadius, wheelOffset) m_encoder(motors), m_wheelGearing(wheelGearing)
{}

