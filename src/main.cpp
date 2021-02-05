#include "Main.h"
#include <Arduino.h>
#include "gamestate/State.h"
#include "gamestate/waitForStart/StateWaitForStart.h"
#include "Logger.h"

char LED_PINS[] = {36,37,38,39,34}; // All GPIO-Pins from a heltec lora v2 that work with digitalWrite

int AMOUNT_LEDS = sizeof(LED_PINS)/sizeof(*LED_PINS);

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
  
  // Sets all leds to outout
  for(int i=0;i<AMOUNT_LEDS;i++)
    pinMode(LED_PINS[i],OUTPUT);

  logger::trace(String(AMOUNT_LEDS)+" led's have been set to pinmode(Output).");

  // Opens the first state
  openGameState(new StateWaitForStart);
}

void loop() {
  // Executes the tick event the open state
  currentState->onTick();
}
