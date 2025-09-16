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


struct Point
{
    public:
        float x, y;


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
        Point add(Point& otherPoint) const;

        /**
         * @brief Subtract one Point from Another
         * 
         * @param otherPoint 
         * @return Point 
         */
        Point subtract(Point& otherPoint) const;

        /**
         * @brief Multiply a Point by a Scalar
         * 
         * @param scalar 
         * @return Point 
         */
        Point multiply(float& scalar) const;

        /**
         * @brief Divide a Point by a Scalar
         * 
         * @param scalar 
         * @return Point 
         */
        Point divide(float& scalar) const;

        /**
         * @brief Add Two Points Together
         * 
         * @param otherPoint 
         * @return Point 
         */
        Point operator+(Point& otherPoint) const;

        /**
         * @brief Subtract one Point from Another
         * 
         * @param otherPoint 
         * @return Point 
         */
        Point operator-(Point& otherPoint) const;

        /**
         * @brief Multiply a Point by a Scalar
         * 
         * @param scalar 
         * @return Point 
         */
        Point operator*(float& scalar) const;

        /**
         * @brief Divide a Point by a Scalar
         * 
         * @param scalar 
         * @return Point 
         */
        Point operator/(float& scalar) const;

        /**
         * @brief Find the Distance to Another Point
         * 
         * @param otherPoint 
         * @return Point 
         */
        float distanceTo(Point& otherPoint) const;

        
        friend std::ostream& operator<<(std::ostream& os, const Point& printPoint);

};


/**
 * @brief Friend Function to Print Point
 * 
 * @param os 
 * @param printPoint 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Point& printPoint);