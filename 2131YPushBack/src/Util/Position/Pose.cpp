#include "Util/Position/Pose.hpp"


Pose::Pose(float x, float y, Angle theta)
    : Point(x,y), theta(theta)
{}

std::ostream& operator<<(std::ostream& os, const Pose& printPose)
{
    os << printPose.x << ", " << printPose.y << ", " << (float)printPose.theta;
    return os;
}

