#include "Chassis/Sensors/MotorEncoder.hpp"
#include "pros/motors.hpp"

MotorEncoder::MotorEncoder(pros::MotorGroup& motors, float wheelRadius, float wheelOffset, float wheelGearing)
    : AbstractEncoder(wheelRadius, wheelOffset), m_encoder(motors), m_wheelGearing(wheelGearing)
{}

float MotorEncoder::getPosition() const
{
    return static_cast<float>(average<double>({m_encoder.get_position(0), m_encoder.get_position(1), m_encoder.get_position(2)}));
}

void MotorEncoder::reset()
{
    m_encoder.tare_position_all();
}

float MotorEncoder::getPosition() const
{

    /* Average all motor positions together */
    std::vector<double> allPositions = m_encoder.get_position_all();

    double totalPosition = std::accumulate(allPositions.begin(), allPositions.end(), 0.0);
    double avgPosition = totalPosition/allPositions.size();

    return 2*M_PI*m_wheelRadius*avgPosition;
}

