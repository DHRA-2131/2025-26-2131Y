/**
 * @file Positioning.hpp
 * @author Ezra Jones (2131Y)
 * @brief Point Class for Positioning
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
        float m_x, m_y;

    
    public:

        /**
         * @brief Construct a new Point object
         * 
         * @param x 
         * @param y 
         */
        Point(float x, float y);


        /**
         * @brief Get X Value
         * 
         * @return float 
         */
        float getX() const;

        /**
         * @brief Get Y Value
         * 
         * @return float 
         */
        float getY() const;

        /**
         * @brief Set X Value
         * 
         * @param x 
         */
        void setX(float x);

        /**
         * @brief Set Y Value
         * 
         * @param y 
         */
        void setY(float y);

        /**
         * @brief Find Distance between Points
         * 
         * @param otherPoint 
         * @return float 
         */
        float distanceTo(Point& otherPoint) const;


        friend std::ostream& operator<<(std::ostream& os, const Point& printPoint);

};

std::ostream& operator<<(std::ostream& os, const Point& printPoint);