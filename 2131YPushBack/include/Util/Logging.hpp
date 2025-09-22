/**
 * @file Logging.hpp
 * @author Quinn Bracken
 * @brief Utility for logging 
 * @version 2.0 
 * @date 2025-09-22
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include <cstdint>
#include <string>
class Logger 
 {
    public:
        enum class debugLevel; //Forward Declaration to make Logger happy
        
        /**
         * @brief Construct a new Logger object
         * 
         * @param Level 
         */
        Logger(debugLevel Level = debugLevel::Status);

        /**
         * @brief Output message to logger
         * 
         * @param message 
         */
        void output(std::string message);

        /**
         * @brief Attach a variable to the logger process to be watched
         * 
         * @param varName 
         * @param variable 
         * @return uint8_t 
         */
        uint8_t attachVar(std::string varName, auto& variable);

        /**
         * @brief Output a var
         * 
         * @param varIdentifier 
         */
        void outputVar(uint8_t varIdentifier);

        /**
         * @brief Output a var
         * 
         * @param varName 
         */
        void outputVar(std::string varName);

        /**
         * @brief Output ALL vars
         * 
         */
        void outputAllVars();


        enum class debugLevel
        {
            None,
            Warning,
            Status,
            Information,
            Debug
        };

        friend std::ostream& operator<<(std::ostream& os, const Logger& printLogger);
 };

 std::ostream& operator<<(std::ostream& os, const Logger& printLogger);