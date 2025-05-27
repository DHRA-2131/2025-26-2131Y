#pragma once


#include <string>

enum class logLocation {
    Drive,
    RobotConfig,
    ExitConditions,
    MathUtils,
    Odom,
    PID,
    Positioning
};


void log(logLocation location, std::string message);