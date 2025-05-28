#include "Utilities/Logging.hpp"
#include <sstream>
#include "pros/misc.hpp"
#include "pros/rtos.hpp"
#include <iostream>

bool sdCardEnabled = 0;

void log(logLocation location, std::string message){
    std::ostringstream output;
    output << pros::millis() << " | ";
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
        
        case logLocation::LVGL:
            output << "LVGL";
        
        default:
            output << "?";

    };
    output << " >> " << message;

    logToSD(output.str());
    std::cout << output.str() << std::endl;


}

void dataLog(std::vector<std::string> csvList){
    std::ostringstream output;
    for (std::size_t i; i < csvList.size(); i++){
        output << csvList.at(i);
    }  
    logToSD(output.str());
    std::cout << output.str() << std::endl;
}

bool enableSDCardLogging(){
    if (pros::usd::is_installed()) {sdCardEnabled = true; return true;}
    sdCardEnabled = false;
    return false;
}

bool disableSDCardLogging(){
    sdCardEnabled = false;
    return false;
}

bool logToSD(std::string data){
    if (sdCardEnabled && pros::usd::is_installed()){
        FILE * logging_file = fopen("/usd/data", "a");
        fputs(data.c_str(), logging_file);
        fclose(logging_file);
        return true;
    }

    //If an Error Occured or SD card not inserted
    sdCardEnabled = false;
    return false;

}