#include "StateIngame.h"
#include "Arduino.h"

void StateIngame::onTriggerButtonPressed(){
    Serial.println("Call from StateIngame: onSwitchButtonPressed");
}