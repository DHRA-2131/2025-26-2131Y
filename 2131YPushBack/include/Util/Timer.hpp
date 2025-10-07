/**
 * @file Timer.hpp
 * @author Ezra Jones (2131Y)
 * @brief Class to Log the Time Taken by a Function
 * @version 2.0
 * @date 2025-09-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#pragma once

#include "Util/Logging.hpp"


class Timer
{
    private:
        uint32_t m_startTime;

    public:

    /**
     * @brief Construct a new Timer object
     * 
     */
    Timer();

    /**
     * @brief Destroy the Timer object
     * 
     */
    ~Timer();

    /**
     * @brief Get the Current Time
     * 
     * @return uint32_t 
     */
    uint32_t getCurrentTime();

    friend std::ostream& operator<<(std::ostream& os, const Timer& printTimer);

};

std::ostream& operator<<(std::ostream& os, const Timer& printTimer);