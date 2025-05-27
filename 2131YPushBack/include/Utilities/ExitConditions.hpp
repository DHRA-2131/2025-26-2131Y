#pragma once

class ExitCondition{

    public:
        ExitCondition(double settleError, double settleTime, double delayTime);

        bool canExit(double value);

    private:

        const double m_settleError;
        const double m_settleTime;
        const double m_delayTime;

        double m_count;


};