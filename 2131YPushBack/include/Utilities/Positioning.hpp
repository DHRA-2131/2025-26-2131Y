/**
 * @file Positioning.hpp
 * @author Ezra Jones (2131Y)
 * @brief Positioning Classes
 * @version 2.0
 * @date 2025-09-15
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#pragma once

#include <iostream>


class Point
{
    private:
        float x, y;

    public:

        /**
         * @brief Construct a new Point object
         * 
         * @param x 
         * @param y 
         */
        Point(float x, float y);


        /**
         * @brief Add Two Points Together
         * 
         * @param otherPoint 
         * @return Point 
         */
        Point add(Point otherPoint);

        /**
         * @brief Subtract one Point from Another
         * 
         * @param otherPoint 
         * @return Point 
         */
        Point subtract(Point otherPoint);

        /**
         * @brief Multiply a Point by a Scalar
         * 
         * @param scalar 
         * @return Point 
         */
        Point multiply(float scalar);

        /**
         * @brief Divide a Point by a Scalar
         * 
         * @param scalar 
         * @return Point 
         */
        Point divide(float scalar);

        /**
         * @brief Add Two Points Together
         * 
         * @param otherPoint 
         * @return Point 
         */
        Point operator+(Point otherPoint);

        /**
         * @brief Subtract one Point from Another
         * 
         * @param otherPoint 
         * @return Point 
         */
        Point operator-(Point otherPoint);

        /**
         * @brief Multiply a Point by a Scalar
         * 
         * @param scalar 
         * @return Point 
         */
        Point operator*(float scalar);

        /**
         * @brief Divide a Point by a Scalar
         * 
         * @param scalar 
         * @return Point 
         */
        Point operator/(float scalar);


        friend std::ostream& operator<<(std::ostream& os, const Point& printPoint);

};

std::ostream& operator<<(std::ostream& os, const Point& printPoint)
{
    os << printPoint.x << ", " << printPoint.y;
    return os;
}