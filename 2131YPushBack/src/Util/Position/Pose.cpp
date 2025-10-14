#include "Util/Position/Pose.hpp"

Pose::Pose(float x, float y, Angle theta)
    : Point(x,y), theta(theta.theta.load())
{}

