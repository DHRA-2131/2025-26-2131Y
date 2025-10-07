#include "Util/Positioning/Point.hpp"

#include <cmath>



Point::Point(float x, float y)
    : m_x(x), m_y(y)
{}


float Point::getX() const
{
    return m_x;
}

float Point::getY() const
{
    return m_y;
}

void Point::setX(float x)
{
    m_x = x;
}

void Point::setY(float y)
{
    m_y = y;
}

float Point::distanceTo(Point& otherPoint) const
{
    return sqrt(pow(this->m_x - otherPoint.m_x, 2) + pow(this->m_y - otherPoint.m_y, 2));
}

std::ostream& operator<<(std::ostream& os, const Point& printPoint)
{
    os << printPoint.m_x << ", " << printPoint.m_y;
    return os;
}