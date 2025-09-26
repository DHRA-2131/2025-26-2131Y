/**
 * @file Pneumatic.hpp
 * @author Quinn Bracken
 * @brief Pneumatic Class for Robot Control
 * @version 2.0
 * @date 2025-09-17
 * 
 * @copyright Copyright (c) 2025
 * 
 */


#pragma once

#include <ostream>
#include "stdint.h"

#include "pros/adi.hpp"
#include "pros/misc.hpp"

 

class Pneumatic : private pros::adi::Pneumatics
{

    public:

        enum class Status{
            Retracted,
            Extended
        }; 

        pros::controller_digital_e_t m_controllerButton;

        /**
         * @brief Construct a new Pneumatic object
         * 
         * @param port 
         * @param startExtended 
         * @param extendedIsLow 
         */
        Pneumatic(pros::controller_digital_e_t controllerButton, std::uint8_t port, bool startExtended, bool extendedIsLow = false);

    
        /**
         * @brief Set Pneumatic State
         * 
         * @param desiredState 
         */
        void set(Status desiredState);
        
        /**
         * @brief Manage Drive Control
         * 
         */
        void driveControl();

        friend std::ostream& operator<<(std::ostream& os, const Pneumatic& printPneumatic);
    
};

std::ostream& operator<<(std::ostream& os, const Pneumatic& printPneumatic);


extern Pneumatic shovelMech;
