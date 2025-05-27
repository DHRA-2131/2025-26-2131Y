#pragma once

#include <math.h>

class Point
{
    public:
        Point(double x, double y);

        double x;
        double y;

        double getDistanceTo(Point& otherPoint);
};

class Pose : public Point 
{
    public:
        Pose(double x, double y, double theta);

        double theta;

        double getAngleTo(Point& otherPoint);
};