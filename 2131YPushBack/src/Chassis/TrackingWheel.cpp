#include "Chassis/TrackingWheel.hpp"
#include "Util/Constants.hpp"


TrackingWheel::TrackingWheel(AbstractEncoder& encoder, float wheelCircumference, float gearRatio, Eigen::Vector2f wheelOffset, bool horizontalWheel = true)
    : m_encoder(encoder), m_wheelCircumference(wheelCircumference), m_gearRatio(gearRatio), m_wheelOffset(wheelOffset), m_horizontalWheel(horizontalWheel), m_encoderToInches(deg_to_rev *  m_wheelCircumference * m_gearRatio)
{}


float TrackingWheel::getPosition() const
{
    return m_encoder.getPosition() * m_encoderToInches;
}


float TrackingWheel::getVelocity() const
{
    return m_encoder.getVelocity() * m_encoderToInches;
}


float TrackingWheel::getAcceleration() const
{
    return m_encoder.getAcceleration() * m_encoderToInches;
}


Eigen::Vector3<float> TrackingWheel::getState() const
{
    return m_encoder.getState() * m_encoderToInches;
}


float TrackingWheel::getCircumference() const
{
    return m_wheelCircumference;
}


float TrackingWheel::getGearRatio() const
{
    return m_gearRatio;
}


Eigen::Vector2f TrackingWheel::getOffset() const
{
    return m_wheelOffset;
}


bool TrackingWheel::getHorizontalWheel() const
{
    return m_horizontalWheel;
}


void TrackingWheel::update(float deltaTime)
{
    m_encoder.update(deltaTime);
}


void TrackingWheel::reset()
{
    m_encoder.reset();
}