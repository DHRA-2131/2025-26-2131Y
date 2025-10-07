#include "Chassis/Sensors/AbstractEncoder.hpp"

// ? Should this just be in the header file?
AbstractEncoder::AbstractEncoder(float wheelRadius, float wheelOffset)
    : m_wheelRadius(wheelRadius), m_wheelOffset(wheelOffset)
{}