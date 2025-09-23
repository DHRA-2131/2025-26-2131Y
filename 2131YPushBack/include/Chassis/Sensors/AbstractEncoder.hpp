/**
 * @file AbstractEncoder.hpp
 * @author Ezra Jones (2131Y)
 * @brief Abstract Encoder Class
 * @version 2.0
 * @date 2025-09-23
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#pragma once


class AbstractEncoder
{
    private:

        float m_wheelRadius;
        float m_wheelOffset;

    public:

        AbstractEncoder(float wheelRadius, float wheelOffset);

        /**
         * @brief Get the Position of the encoder in degrees
         * 
         * @return float 
         */
        virtual float getPosition() const = 0;

        /**
         * @brief Reset the Encoder's Values
         * 
         */
        virtual void reset() = 0;


};