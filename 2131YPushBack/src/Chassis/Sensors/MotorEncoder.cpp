#include "Chassis/Sensors/MotorEncoder.hpp"
#include "math.h"
#include <numeric>

MotorEncoder::MotorEncoder(pros::MotorGroup& motors, float wheelRadius, float wheelOffset, float wheelGearing)
    : AbstractEncoder(wheelRadius, wheelOffset), m_encoder(motors), m_wheelGearing(wheelGearing)
{}

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

