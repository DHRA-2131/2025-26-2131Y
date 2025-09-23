/**
 * @file MovementSettings.hpp
 * @author Ezra Jones (2131Y)
 * @brief Settings for Drive Movement
 * @version 2.0
 * @date 2025-09-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#pragma once


enum class arcDirection
{
    noArc = 0, 
    arcRight, 
    arcLeft
};


struct driveToPointSettings
{
    public:

        bool forward = true;
        bool async = false;
};

struct turnToPointSettings
{
    
};

struct turnToHeadingSettings
{

};