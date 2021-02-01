#include "State.h"
#include "Logger.h"

State::~State(){}

void State::onStateOpen(){}
void State::onStateClose(){}
void State::onSwitchButtonPressed(){}
void State::onTick(){}
void State::onTriggerButtonPressed(){}