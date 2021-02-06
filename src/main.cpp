#include "Main.h"
#include <Arduino.h>
#include "gamestate/State.h"
#include "gamestate/waitForStart/StateWaitForStart.h"
#include "Logger.h"

char LED_PINS[] = {32,33,25,26,27}; // All GPIO-Pins from a heltec lora v2 that work with digitalWrite

int BUTTON_PIN_SWITCH = 14;
int BUTTON_PIN_TRIGGER = 12;

int AMOUNT_LEDS = sizeof(LED_PINS)/sizeof(*LED_PINS);

State* currentState;

bool diffcultyEasy=true;

void openGameState(State* state){
  // Checks if a previous state is still existing
  if(currentState!=NULL){
    // Executes the exit-code
    currentState->onStateClose();

    // Deletes the object
    delete currentState;
  }

  logger::debug("Opening next state: "+state->getStateName());

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

  logger::debug(String(AMOUNT_LEDS)+" led's have been set to pinmode(Output).");

  // Opens the first state
  openGameState(new StateWaitForStart);
}

void loop() {
  // Executes the tick event the open state
  currentState->onTick();
}
