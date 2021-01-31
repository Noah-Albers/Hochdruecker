#include "State.h"
#include "Logger.h"

State::~State(){}

void State::onSwitchButtonPressed(){
    logger::warning("Call from State: onSwitchButtonPressed");
}
void State::onTick(){
    logger::error("Call from State: onTick");
}
void State::onTriggerButtonPressed(){
    logger::debug("Call from State: onTriggerButtonPressed");
}