#pragma once

#include <string>
#include "pros/rtos.hpp"
#include <iostream>

enum class logLocation {
    Drive,
    RobotConfig,
    ExitConditions,
    MathUtils,
    Odom,
    PID,
    Positioning,
    LVGL,
    MAIN,
    LOG,
    Kalman
};


void log(logLocation location, const char* fmt, ...);
void dataLog(std::vector<std::string> csvList);

bool enableSDCardLogging();
bool disableSDCardLogging();

static bool logToSD(std::string data);


template <typename T> class Logger {
    public:

        //Contemplating moving this to .tpp file
        Logger(std::string VarName, T* Data, int refreshRate) : m_varName(VarName), m_dataPtr(Data), m_prevData(*Data), m_refreshRate(refreshRate),
            m_logTask([this]{
                log(logLocation::LOG, "Created Logger for variable at %i", m_dataPtr);

                if (*m_dataPtr != m_prevData){
                    std::cout << pros::millis() << " | " << m_varName << " >> " << *m_dataPtr;
                    m_prevData = *m_dataPtr;
                }
                pros::delay(m_refreshRate);
            })
        {} //Use ptrs because theres a chance the data goes out of scope or becomes null

        ~Logger();

        void startLogging();
        void stopLogging();

    private:
        pros::Task m_logTask;

        std::string m_varName;
        T* m_dataPtr;
        T m_prevData;

        int m_refreshRate;

};


