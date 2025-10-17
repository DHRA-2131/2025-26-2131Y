/**
 * @file PID.hpp
 * @author Quinn Bracken & Ezra Jones (V2.0)
 * @brief 
 * @version 3.0
 * @date 2025-10-08
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 #pragma once


class PID
{
    private:
        float m_kP;
        float m_kI;
        float m_kD;

        float m_integral;
        float m_prevError;
        float m_integralWindup;

    public:

        /**
         * @brief Construct a new PIDController object
         * 
         * @param kP 
         * @param kI 
         * @param kD 
         */
        PID(float kP, float kI, float kD, float integralWindup);

        /**
         * @brief Update the PID Controller
         * 
         * @param error 
         * @return float 
         */
        float calculate(float error, float deltaTime);

        /**
         * @brief Reset PID Values
         */
        void reset();

};