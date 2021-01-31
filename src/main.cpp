#include <Arduino.h>
#include "gamestate/State.h"
#include "gamestate/Ingame/StateIngame.h"
#include "Logger.h"

void setup() {
  // Starts the serial output
  Serial.begin(115200);

  // Sets the log-level to log all
  logger::setLogLevel(logger::ALL);

  State* s;

  s = new StateIngame;

  s->onTick();

  s->onTriggerButtonPressed();

  s->onSwitchButtonPressed();

  delete s;
}

void loop() {}
