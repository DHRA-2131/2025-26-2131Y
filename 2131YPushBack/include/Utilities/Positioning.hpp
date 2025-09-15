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


struct Point
{
    public:
        int x, y;


        Point(int x, int y);


        Point operator+(Point otherPoint);
        Point operator-(Point otherPoint);
        Point operator*(Point otherPoint);
        Point operator/(Point otherPoint);

};