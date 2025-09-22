#include "Util/Positioning/Pose.hpp"
#include "Angle.hpp"
#include "Point.hpp"
#include <ostream>

Pose::Pose(float x, float y, Angle theta)
    : Point(x, y), m_theta(theta)
{}

Angle Pose::getTheta() const
{
    return m_theta;
}

void Pose::setTheta(Angle& theta)
{
    m_theta = theta;
}

std::ostream& operator<<(std::ostream& os, const Pose& printPose){
    os << printPose.getX() << printPose.getY() << printPose.getTheta();
    return os;
}