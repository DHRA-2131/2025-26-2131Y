#pragma once

#include <math.h>

class Point
{
    public:
        double x;
        double y;

        void getDistanceTo(Point& otherPoint);
};

class Pose : public Point
{
    public:
        double theta;

        void getAngleTo(Point& otherPoint);
};