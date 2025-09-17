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

Point Point::add(Point& otherPoint) const
{
    return Point(this->m_x + otherPoint.m_x, this->m_y + otherPoint.m_y);
}


Point Point::subtract(Point& otherPoint) const
{
    return Point(this->m_x - otherPoint.m_x, this->m_y - otherPoint.m_y);
}


Point Point::multiply(float& scalar) const
{
    return Point(this->m_x * scalar, this->m_y * scalar);
}


Point Point::divide(float& scalar) const
{
    return Point(this->m_x / scalar, this->m_y / scalar);
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
    return sqrt(pow(this->m_x - otherPoint.m_x, 2) + pow(this->m_y - otherPoint.m_y, 2));
}

std::ostream& operator<<(std::ostream& os, const Point& printPoint)
{
    os << printPoint.m_x << ", " << printPoint.m_y;
    return os;
}