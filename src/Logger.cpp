#include "Logger.h"
#include <Arduino.h>

#define PREFIX_TRACE "TRACE"
#define PREFIX_DEBUG "DEBUG"
#define PREFIX_INFO "INFO"
#define PREFIX_WARNING "WARNING"
#define PREFIX_ERROR "ERROR"

namespace logger{

    const int TRACE = 1;
    const int DEBUG = 2;
    const int INFO = 4;
    const int WARNING = 8;
    const int ERROR = 16;

    const int ALL = ~0;
    const int OFF = 0;

    int log_level = ALL;

    void output_logging(int level,String prefix,String text){

        // Checks if the priorityLevel level is not printable
        if((log_level & level) <= 0)
            return;

        // Outputs the text with the prefix
        Serial.println("["+prefix+"] "+text);
    }

    void setLogLevel(int level){
        log_level = level;
    }
    void trace(String text){
        output_logging(TRACE,PREFIX_TRACE,text);
    }
    void debug(String text){
        output_logging(DEBUG,PREFIX_DEBUG,text);
    }
    void info(String text){
        output_logging(INFO,PREFIX_INFO,text);
    }
    void warning(String text){
        output_logging(WARNING,PREFIX_WARNING,text);
    }
    void error(String text){
        output_logging(ERROR,PREFIX_ERROR,text);
    }
}