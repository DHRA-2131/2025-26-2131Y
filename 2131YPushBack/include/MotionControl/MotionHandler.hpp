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
#pragma once

class MotionHandler
{
    private:
        MotionHandler() = default;
        
    public:
        /* Delete so MotionHandler Cannot be copied */
        MotionHandler(const MotionHandler&) = delete;
        MotionHandler& operator=(MotionHandler const&) = delete;

        /**
         * @brief Get instance of singleton
         * 
         * @return MotionHandler* 
         */
        MotionHandler* instance();

        /**
         * @brief Request Control of Chassis
         *
         * If Chassis is in use and blocking is set to true thread will wait untill control is secured.
         * Otherwise will return -1 (Could not attain lock), or 1 (Lock Secured)
         * 
         * @param blocking 
         * @return int (Lock Status) 
         */
        int requestControl(bool blocking = true);

        /**
         * @brief Release control of the chassis
         * 
         */
        void relinquishControl();


};



