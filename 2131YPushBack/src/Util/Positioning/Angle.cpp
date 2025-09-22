#include "Util/Positioning/Angle.hpp"

#include <math.h>


Angle::Angle(float theta, bool degrees)
    : m_theta(
        (degrees) ? theta * (M_PI / 180) : theta
    )
{}

float Angle::getTheta(bool degrees) const 
{
    return (degrees) ? m_theta * (M_PI / 180) : m_theta;
}

void Angle::setTheta(float theta, bool degrees){
    m_theta = (degrees) ? theta * (M_PI / 180) : theta;
    wrapAngle();
}

float Angle::wrapAngle(){
    return  m_theta = (m_theta > (M_PI)) ? m_theta - (2 * M_PI) : ((m_theta < (-1 * M_PI)) ? m_theta + (2 * M_PI) : m_theta);
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

std::ostream& operator<<(std::ostream& os, const Angle& printAngle){
    os << printAngle.m_theta;
    return os;
}




