#include "Main.h"
#include <Arduino.h>
#include "gamestate/State.h"
#include "gamestate/waitForStart/StateWaitForStart.h"
#include "Logger.h"

State* currentState;

void openGameState(State* state){
  // Checks if a previous state is still existing
  if(currentState!=NULL){
    // Executes the exit-code
    currentState->onStateClose();

    // Deletes the object
    delete currentState;
  }

  // Opens the new state
  currentState=state;
}

void setup() {
  // Starts the serial output
  Serial.begin(115200);

  // Sets the log-level to log all
  logger::setLogLevel(logger::ALL);

  // Opens the first state
  openGameState(new StateWaitForStart);
}

void loop() {
  // Executes the tick event the open state
  currentState->onTick();
}
