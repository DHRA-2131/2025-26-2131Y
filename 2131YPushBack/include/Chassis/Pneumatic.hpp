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

#include <iostream>
#include <ostream>
#include "stdint.h"

#include "pros/adi.hpp"

 

class Pneumatic : pros::adi::Pneumatics
{

    public:

        /**
         * @brief Construct a new Pneumatic object
         * 
         * @param port 
         * @param startExtended 
         * @param extendedIsLow 
         */
        Pneumatic(std::uint8_t port, bool startExtended, bool extendedIsLow = false);

    
        /**
         * @brief 
         * 
         * @return std::int32_t 
         */
        std::int32_t set();

        friend std::ostream& operator<<(std::ostream& os, const Pneumatic& printPneumatic);
    
 };

 std::ostream& operator<<(std::ostream& os, const Pneumatic& printPneumatic);
