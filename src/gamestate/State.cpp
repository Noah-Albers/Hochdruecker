#include "State.h"
#include "Arduino.h"

State::~State(){}

void State::onSwitchButtonPressed(){
    Serial.println("Call from State: onSwitchButtonPressed");
}
void State::onTick(){
    Serial.println("Call from State: onTick");
}
void State::onTriggerButtonPressed(){
    Serial.println("Call from State: onTriggerButtonPressed");
}