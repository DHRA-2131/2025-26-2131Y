#pragma once

class PID 
{
    
    public:

        /**
         * @brief PID Controller Constructor
         *
         * @param kP
         * @param kI
         * @param kD
         */
        PID(double kP, double kI, double kD);


        /**
         * @brief Calculate result of PID Algorithm
         *
         * @param Error
         */
        double calculate(double Error);

        /**
         * @brief Reset PID variables
         *
         */
        void reset();


    private:

        const double m_kp;
        const double m_ki;
        const double m_kd;

        const double m_integralDamp;


        double m_prevError;
        double m_derivative;
        double m_integral;





};

extern PID lateralPID;
extern PID angularPID;
