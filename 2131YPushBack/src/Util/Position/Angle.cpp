#include "Util/Position/Angle.hpp"
#include "Math.h"
#include "Util/Constants.hpp"

Angle::Angle(float theta, bool degrees)
    : theta((degrees) ? theta * deg_to_rad : theta)
{}

Angle::Angle(Angle const& other)
{
    this->theta = other.theta.load();
}

Angle& Angle::operator=(const Angle& other)
{
    this->theta = other.theta.load();
    return *this;
}

float Angle::wrapAngle()
{
    return  theta = (theta > (M_PI)) ? theta - (2 * M_PI) : ((theta < (-1 * M_PI)) ? (float)theta + (2 * M_PI) : (float)theta);
}



void Angle::setTheta(float theta, bool degrees)
{
    this->theta = (degrees) ? theta * deg_to_rad : theta;
}

float Angle::getTheta(bool degrees)
{
    return (degrees) ? (this->theta.load() * deg_to_rad) : this->theta.load();
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


 