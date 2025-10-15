#include "Util/Position/Point.hpp"

Point::Point(float x, float y)
    : x(x), y(y)
{}

Point::Point(const Point& other)
{
    this->x = other.x.load();
    this->y = other.y.load();
}

Point& Point::operator=(const Point& other)
{
    this->x = other.x.load();
    this->y = other.y.load();
    return *this;
}

float Point::distanceTo(Point& otherPoint) const
{
    return sqrt(pow(this->x - otherPoint.x, 2) + pow(this->y - otherPoint.y, 2));
}

