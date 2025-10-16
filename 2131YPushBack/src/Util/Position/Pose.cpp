#include "Util/Position/Pose.hpp"

Pose::Pose(float x, float y, Angle theta)
    : Point(x,y), theta(theta.theta.load())
{}

std::ostream& operator<<(std::ostream& os, const Pose& printPose)
{
    os << printPose.x << ", " << printPose.y << ", " << printPose.theta.theta;
    return os;
}