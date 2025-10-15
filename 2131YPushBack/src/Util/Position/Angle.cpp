#include "Util/Position/Angle.hpp"
#include "Math.h"
#include "Eigen/Eigen"

Angle::Angle(float theta, bool degrees)
    : theta((degrees) ? theta*M_PI/180 : theta)
{}

Angle::Angle(const Angle& other)
{
    this->theta = other.theta.load();
}

Angle& Angle::operator=(const Angle& other)
{
    this->theta = other.theta.load();
}


void Angle::setEigenMatrix(Eigen::RowVector<float, 1> matrix, bool degrees)
{
    this->theta = (degrees) ? matrix(1)*M_PI/180 : matrix(1);
}

Eigen::RowVector<float, 1> Angle::getEigenMatrix(bool degrees)
{
    return Eigen::RowVector<float, 1>((degrees) ? this->theta*180/M_PI : (float)this->theta);
}

 Angle Angle::operator+(Angle& otherAngle) const
 {
    return Angle(theta + (float)otherAngle);
 }

 Angle Angle::operator-(Angle& otherAngle) const
 {
    return Angle(theta - (float)otherAngle);
 }

 Angle Angle::operator*(float& scalar) const
 {
    return Angle(theta * scalar);
 }

 Angle Angle::operator/(float& scalar) const
 {
    return Angle(theta / scalar);
 }


 