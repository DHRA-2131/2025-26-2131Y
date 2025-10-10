/**
 * @file Controller.hpp
 * @author Quinn Bracken (2131Y)
 * @brief 
 * @version 0.1
 * @date 2025-10-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */

 //Ezra is this stupid?

#pragma once

#include <functional>
#include <utility>


#include "pros/misc.h"
#include "pros/misc.hpp"

#include "Eigen/Eigen"

class Controller
{
    private:
        std::vector<std::pair<pros::controller_digital_e_t, std::function<void(bool)>>> m_callbacks;
        std::function<void(Eigen::RowVector4d)> m_analogFunction;

    public:
        pros::Controller prosController;

        /**
         * @brief Construct a new Controller object for specified controller
         * 
         * @param id 
         */
        Controller(pros::controller_id_e_t id);
        
        /**
         * @brief Set the Callback function for a button
         * 
         * @param callbackFunction 
         */
        void setCallback(pros::controller_digital_e_t, std::function<void(bool)> callbackFunction);

        /**
         * @brief Set the Function that controls the analog sticks
         *
         * @param analogFunction 
         */
        void setAnalogFunction(std::function<void(Eigen::RowVector4d)> analogFunction);

        /* Default analog controls */
        static void tank(Eigen::RowVector4d Axis);
        static void splitArcade(Eigen::RowVector4d Axis);
};
