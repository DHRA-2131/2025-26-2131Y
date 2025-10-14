#include "Util/Position/Point.hpp"

Point::Point(float x, float y)
    : x(x), y(y)
{}

float Point::distanceTo(Point& otherPoint) const
{
    return sqrt(pow(this->x - otherPoint.x, 2) + pow(this->y - otherPoint.y, 2));
}

