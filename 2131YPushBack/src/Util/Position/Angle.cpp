#include "Util/Position/Angle.hpp"
#include "Math.h"
#include "Util/Constants.hpp"

Angle::Angle(float theta, bool degrees)
    : theta((degrees) ? theta * rad_to_deg : theta)
{}

Angle::Angle(const Angle& other)
{
    this->theta = other.theta.load();
}

Angle& Angle::operator=(const Angle& other)
{
    this->theta = other.theta.load();
    return *this;
}


void Angle::setTheta(float theta, bool degrees)
{
    this->theta = (degrees) ? theta * rad_to_deg : theta;
}

float Angle::getTheta(bool degrees)
{
    return (degrees) ? (this->theta.load() * rad_to_deg) : this->theta.load();
}

 Angle Angle::operator+(Angle& otherAngle) const
 {
    return Angle(theta + otherAngle.theta);
 }

 Angle Angle::operator-(Angle& otherAngle) const
 {
    return Angle(theta - otherAngle.theta);
 }

 Angle Angle::operator*(float& scalar) const
 {
    return Angle(theta * scalar);
 }

 Angle Angle::operator/(float& scalar) const
 {
    return Angle(theta / scalar);
 }


 