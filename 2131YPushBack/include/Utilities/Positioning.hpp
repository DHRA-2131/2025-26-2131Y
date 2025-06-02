#pragma once

#include <math.h>

class Point
{
    public:

        /**
         * @brief Create a new Point Object
         *
         * @param x
         * @param y
         */
        Point(double x, double y);

        double x;
        double y;

        /**
         * @brief Return distance to another point
         *
         * @param otherPoint
         */

        double getDistanceTo(Point& otherPoint);
};

class Pose : public Point 
{
    public:

        /**
         * @brief Create a new Pose Object
         *
         * @param x
         * @param y
         * @param theta
         */
        Pose(double x, double y, double theta);

        double theta;

        /**
         * @brief return angle to another point
         *
         * @param otherPoint
         */
        double getAngleTo(Point& otherPoint);
};