#include "Timer.h"
#include <Arduino.h>

Timer::Timer(){
    this->reset();
}

void Timer::reset(){
    // Resets the time stamp to the current millis
    this->timeStamp=millis();
}

bool Timer::hasReached(long timeInMs){
    return this->getTimeDifference() >= timeInMs;
}

long Timer::getTimeDifference(){
    return millis()-this->timeStamp;
}