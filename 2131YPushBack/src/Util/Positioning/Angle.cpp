#include "Util/Positioning/Angle.hpp"

#include <math.h>


Angle::Angle(float theta, bool degrees)
    : m_theta(theta), m_degrees(degrees)
{}

float Angle::getTheta() const 
{
    //Do we want this as a ternerary statement (?:) or an if statement? (if/else)
    if (m_degrees) {
        return m_theta*(M_PI/180);
    }
    else {
        return m_theta;
    }
}

bool Angle::getDegrees() const
{
    return m_degrees;
}

void Angle::setTheta(float theta){
    m_theta = theta;
}

void Angle::setDegrees(bool degrees){
    m_degrees = degrees;
}

Angle Angle::add(Angle& otherAngle) const
{
    return Angle(this->m_theta + otherAngle.m_theta);
}

Angle Angle::subtract(Angle& otherAngle) const
{
    return Angle(this->m_theta - otherAngle.m_theta);
}

Angle Angle::multiply(float& scalar) const
{
    return Angle(this->m_theta * scalar);
}

Angle Angle::divide(float& scalar) const
{
    return Angle(this->m_theta / scalar);
}

Angle Angle::operator+(Angle& otherAngle) const
{
    return this->add(otherAngle);
}

Angle Angle::operator-(Angle& otherAngle) const
{
    return this->subtract(otherAngle);
}

Angle Angle::operator*(float& scalar) const
{
    return this->multiply(scalar);
}

Angle Angle::operator/(float& scalar) const
{
    return this->divide(scalar);
}




