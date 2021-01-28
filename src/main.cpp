#include <Arduino.h>
#include "gamestate/State.h"
#include "gamestate/Ingame/StateIngame.h"

void setup() {
  State* s;

  s = new StateIngame;

  s->onTick();

  s->onTriggerButtonPressed();

  s->onSwitchButtonPressed();

  delete s;
}

void loop() {}