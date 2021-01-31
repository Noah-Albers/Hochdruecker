#pragma once
#include <Arduino.h>

namespace logger{
    
    extern const int TRACE; // For extremly detailed debug informations
    extern const int DEBUG; // For normal debug informations that can be used later on
    extern const int INFO; // For infos that are commonly used throughout the program. Helps to understand the flow and some other functions
    extern const int WARNING; // For warnings that are unexpexted by the program and could case some sort of error
    extern const int ERROR; // For errors where the program could or would stop impediatly and where a dev/support sould take a look at

    extern const int ALL; // Turns all logging levels on
    extern const int OFF; // Turns all logging levels off

    // The logging level
    extern int log_level;

    /**
     * Used internally to output to the serial connection using one function
     * @param level the level of logging. Used to determin if the specific output is allowed
     * @param prefix the prefix that should be written before the output text
     * @param text the text that should be outputted
     */
    void output_logging(int level,String prefix,String text);

    /**
     * Sets the logging level
     * 
     * @param level the logging level. Use | between the different levels to include multiple.
     * Example: DEBUG | INFO would only let Debug and info logs apear on the screen
     */
    void setLogLevel(int level);

    /**
     * Function to call when wanting to output infos
     */

    void trace(String text);
    void debug(String text);
    void info(String text);
    void warning(String text);
    void error(String text);
    
}