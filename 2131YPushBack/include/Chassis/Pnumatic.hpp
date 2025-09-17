/**
 * @file Pnumatic.hpp
 * @author Quinn Bracken
 * @brief Pnumatic Class for Robot Control
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
 


 class Pnumatic
 {
    public:

        /**
         * @brief Construct a new Pnumatic object
         *
         * @param port
         * @param inverted
         */
        Pnumatic(uint8_t port, bool inverted);

        /**
         * @brief Initializes Pnumatic
         */
        void init();

        /**
         * @brief Set state of pnumatic
         *
         * @param state
         */
        void set(bool state);

        /**
         * @brief Get state of pnumatic
         *
         * @return state
         */
        bool get();

        /**
         * @brief Toggle pnumatic state
         */
        void toggle();

        friend std::ostream& operator<<(std::ostream& os, const Pnumatic& printPnumatic);
    
    private:
        uint8_t m_port;
        bool m_state;

        const bool m_inverted;
 };

 std::ostream& operator<<(std::ostream& os, const Pnumatic& printPnumatic);
