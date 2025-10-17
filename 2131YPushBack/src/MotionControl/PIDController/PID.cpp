#include "MotionControl/PIDController/PID.hpp"
#include "Util/MathFunctions.hpp"
#include "Util/Constants.hpp"
#include "math.h"



float m_kP;
float m_kI;
float m_kD;

float m_integral;
float m_prevError;


PID::PID(float kP, float kI, float kD, float integralWindup)
    : m_kP(kP), m_kI(kI), m_kD(kD), m_integral(0.0f), m_prevError(0.0f), m_integralWindup(integralWindup)
{}


float PID::calculate(float error, float deltaTime)
{
    // Convert Milliseconds to Seconds
    deltaTime *= millis_to_sec;

    // Calculate Integral Using Trapezoidal Integration
    m_integral += ((error + m_prevError) / 2.0f) * deltaTime;

    // Reset Integral if Sign Changes
    if (sign<float>(error) != sign<float>((m_prevError))) 
        m_integral = 0;

    // Reset Integral if Value is has Changed Considerably
    if (fabs(error) > m_integralWindup) 
        m_integral = 0;
    
    // Shrink Integral Value to Prevent Integral Windup
    m_integral *= 0.99;

    // Calculate Derivative
    float derivative = (error - m_prevError) / deltaTime;
    m_prevError = error;

    // Calculate Output
    return (m_kP * error) + (m_kI * m_integral) + (m_kD * derivative);
}


void PID::reset()
{
    m_integral = 0.0f;
    m_prevError = 0.0f;
}

