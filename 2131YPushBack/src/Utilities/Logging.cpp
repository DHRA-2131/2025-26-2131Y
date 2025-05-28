#include "Utilities/Logging.hpp"
#include <sstream>
#include "pros/misc.hpp"
#include "pros/rtos.hpp"
#include <iostream>
#include "stdarg.h"

bool sdCardEnabled = 0;

//I hate doing this like this but its the only way to handle format specifiers
void log(logLocation location, const char* fmt, ...){
    std::ostringstream output;

    va_list args;
    va_start(args, fmt);

    std::ostringstream formattedMsg;
    for (const char *character = fmt; *character != '\0'; character++){
        
        //if character is "normal";
        if (*character != '%'){
            formattedMsg << *character;
        
            continue; //Skip rest of lines
        }

        //If % format specifier is read
        character++; //Increase character count to next character

        switch (*character){
            case 'd':
            case 'i':
                formattedMsg << va_arg(args, int);
                break;
            
            case 'f':
                formattedMsg << va_arg(args, double);
                break;
            
            case 's':
                formattedMsg << va_arg(args, char*);
                break;
            
            case 'c':
                //Double check converting to char for outputting works
                formattedMsg << (char)va_arg(args, int);
                break;

            default:
                formattedMsg << '%' << *character;
            
            
        }
        
    }

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
    output << " >> " << formattedMsg.str();

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