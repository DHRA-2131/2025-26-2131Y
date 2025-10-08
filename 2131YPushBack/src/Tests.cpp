#include "MotionControl/MotionHandler.hpp"
void MotionHandlerTest()
{
    MotionHandler::instance();
    pros::Task task([]{
            while(true){
            MotionHandler::instance()->requestControl();
            pros::delay(5000);
            MotionHandler::instance()->relinquishControl();
        }
        }); //pros::Task
    while(true){
        
        MotionHandler::instance()->requestControl();
        pros::delay(7000);
        MotionHandler::instance()->relinquishControl();
    }//while true
}