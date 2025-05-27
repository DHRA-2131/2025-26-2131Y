#include "Utilities/Logging.hpp"
#include <sstream>
#include "pros/rtos.hpp"

void log(logLocation location, std::string message){
    std::ostringstream output;
    output << pros::millis << " | ";
    switch (location){
        case logLocation::Drive:
            output << "Drive";
            break;
        
        case logLocation::RobotConfig:
            output << "RobotConfig";
            break;

        case logLocation::ExitConditions:
            output << "Exit Conditions";
            break;

        case logLocation::MathUtils:
            output << "Math Utils";
            break;
        
        case logLocation::Odom:
            output << "Odom";
            break;

        case logLocation::PID:
            output << "PID";
            break;
        
        case logLocation::Positioning:
            output << "Positioning";
            break;
        
        default:
            output << "?";

    };
    output << " << " << message;
}