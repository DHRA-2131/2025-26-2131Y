/**
 * @file PIDController.hpp
 * @author Ezra Jones (2131Y)
 * @brief Class to Manage PID Controller Calculations
 * @version 2.0
 * @date 2025-09-18
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#pragma once


class PIDController
{
    private:
        float m_kP;
        float m_kI;
        float m_kD;

        float m_integral;
        float m_prevError;

    public:

        /**
         * @brief Construct a new PIDController object
         * 
         * @param kP 
         * @param kI 
         * @param kD 
         */
        PIDController(float kP, float kI, float kD);

        /**
         * @brief Update the PID Controller
         * 
         * @param error 
         * @return float 
         */
        float update(float error);

        /**
         * @brief Reset PID Values
         */
        void reset();

};