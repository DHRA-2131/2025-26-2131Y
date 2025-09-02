#pragma once

#include <cstdint>
class ExitCondition
{

    public:

        /**
         * @brief Exit Condition constructor
         *
         * @param settleError
         * @param settleTime
         * @param delayTime
         */
        ExitCondition(double settleError, double settleTime, double delayTime);

        bool canExit(double value);

    private:

        const double m_settleError;
        const double m_settleTime;
        const double m_delayTime;

        uint8_t m_count;


};