#include "Utilities/PID.hpp"
#include "Competition/RobotConfig.hpp"
#include "Utilities/Logging.hpp"

PID::PID(double kP, double kI, double kD) : m_kp(kP), m_ki(kI), m_kd(kD), m_derivative(0), m_prevError(0), m_integral(0), m_integralDamp(0.95)
{}


double PID::calculate(double error){
    
    m_integral += error;
    m_integral *= m_integralDamp;

    m_derivative = error - m_prevError;

    double output = (error*m_kp) + (m_integral*m_ki) + (m_derivative*m_kd);

    //log(logLocation::PID, "Percentage of Output - kP: %f, kI: %f, kD: %f", (error*m_kp)/output, (m_integral*m_ki)/output, (m_derivative*m_kd));

    m_prevError = error;
    return output;
}

void PID::reset(){
    m_derivative = 0;
    m_prevError = 0;
    m_integral = 0;
}

#if PROG_CHASSIS

PID lateralPID(8, 0, 40);
PID angularPID(0, 0, 0);

#else

PID lateralPID(8,0,40);
PID angularPID(0.75,0,0); //kp 0.5

#endif