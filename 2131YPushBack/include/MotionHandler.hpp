/**
 * @file MotionHandler.hpp
 * @author Quinn Bracken
 * @brief 
 * @version 3.0
 * @date 2025-10-07
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#ifndef _MOTION_HANDLER_HPP_
#define _MOTION_HANDLER_HPP_

#include "pros/rtos.h"

class MotionHandler
{
    private:
        MotionHandler() = default;
        
    public:
        /* Delete so MotionHandler Cannot be copied */
        MotionHandler(const MotionHandler&) = delete;
        MotionHandler& operator=(MotionHandler const&) = delete;

        MotionHandler* get();

        void requestControl();
        void relinquishControl();


};

#endif

