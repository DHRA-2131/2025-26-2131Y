#include "Util/PIDController.hpp"


PIDController::PIDController(float kP, float kI, float kD)
    : m_kP(kP), m_kI(kI), m_kD(kD), m_integral(0), m_prevError(0)
{}


float PIDController::update(float error)
{
    // Calculate Integral Value
    m_integral += error;

    // Calculate Derivative Value
    float derivative = error - m_prevError;

    // Reset Previous Error
    m_prevError = error;
    
    // Return PID Output
    return (m_kP * error) + (m_kI * m_integral) + (m_kD * derivative);
}