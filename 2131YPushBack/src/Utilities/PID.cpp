#include "Utilities/PID.hpp"

PID::PID(double kP, double kI, double kD) : m_kp(kP), m_ki(kI), m_kd(kD), m_derivative(0), m_prevError(0), m_integral(0), m_integralDamp(1)
{}


double PID::calculate(double error){
    
    m_integral += error;
    m_integral *= m_integralDamp;

    m_derivative = error - m_prevError;

    double output = (error*m_kp) + (m_integral*m_ki) + (m_derivative*m_kd);

    m_prevError = error;
    return output;
}

void PID::reset(){
    m_derivative = 0;
    m_prevError = 0;
    m_integral = 0;
}


PID lateralPID(0,0,0);
PID angularPID(0,0,0);