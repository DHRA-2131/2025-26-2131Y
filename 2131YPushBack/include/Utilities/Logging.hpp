#pragma once


#include <string>

enum class logLocation {
    Drive,
    RobotConfig,
    ExitConditions,
    MathUtils,
    Odom,
    PID,
    Positioning,
    LVGL,
    MAIN
};


void log(logLocation location, const char* fmt, ...);
void dataLog(std::string csvList);

bool enableSDCardLogging();
bool disableSDCardLogging();

static bool logToSD(std::string data);

