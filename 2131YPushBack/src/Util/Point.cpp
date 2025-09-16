#include "Util/Positioning/Point.hpp"



Point::Point(float x, float y)
    : x(x), y(y)
{}

Point Point::add(Point& otherPoint) const
{
    return Point(this->x + otherPoint.x, this->y + otherPoint.y);
}


Point Point::subtract(Point& otherPoint) const
{
    return Point(this->x - otherPoint.x, this->y - otherPoint.y);
}


Point Point::multiply(float& scalar) const
{
    return Point(this->x * scalar, this->y * scalar);
}


Point Point::divide(float& scalar) const
{
    return Point(this->x / scalar, this->y / scalar);
}


Point Point::operator+(Point& otherPoint) const
{
    return this->add(otherPoint);
}


Point Point::operator-(Point& otherPoint) const
{
    return this->subtract(otherPoint);
}


Point Point::operator*(float& scalar) const
{
    return this->multiply(scalar);
}


Point Point::operator/(float& scalar) const
{
    return this->divide(scalar);
}

float Point::distanceTo(Point& otherPoint) const
{
    
}

std::ostream& operator<<(std::ostream& os, const Point& printPoint)
{
    os << printPoint.x << ", " << printPoint.y;
    return os;
}