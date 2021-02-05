#include "State.h"
#include <Arduino.h>

State::State(String statename){
    this->statename=statename;
}

State::~State(){}

void State::onStateOpen(){}
void State::onStateClose(){}
void State::onSwitchButtonPressed(){}
void State::onTick(){}
void State::onTriggerButtonPressed(){}

String State::getStateName(){
    return this->statename;
}