#pragma once

class PID {
    
    public:
        PID(double kP, double kI, double kD);

        double calculate(double Error);
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
