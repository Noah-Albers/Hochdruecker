#include "Main.h"
#include <Arduino.h>
#include "gamestate/State.h"
#include "gamestate/waitForStart/StateWaitForStart.h"
#include "Logger.h"
#include "CompileConfig.h"

State* currentState;

bool diffcultyEasy=true;

Button triggerButton = Button(BUTTON_PIN_TRIGGER,[&]{
  currentState->onTriggerButtonPressed();
});
Button switchButton = Button(BUTTON_PIN_SWITCH,[&]{
  diffcultyEasy=!diffcultyEasy;
});

void openGameState(State* state){
  // Checks if a previous state is still existing
  if(currentState!=NULL){
    // Executes the exit-code
    currentState->onStateClose();

    // Deletes the object
    delete currentState;
  }

  logger::debug("Opening state: "+state->getStateName());

  // Opens the new state
  currentState=state;
}

void clearLeds(){
  // Disables all leds
  for(int i=0;i<AMOUNT_LEDS;i++)
      ledcWrite(i,0);
}

void setup() {
  // Starts the serial output
  Serial.begin(115200);
  
  // Sets the log-level to log all
  logger::setLogLevel(logger::ALL);
  
  // Sets all leds to outout
  for(int i=0;i<AMOUNT_LEDS;i++){
    // Setups the channel at i
    ledcSetup(i,PWM_FREQ,PWM_RESOLUTION);
    // Bind the pin to that channel
    ledcAttachPin(LED_PINS[i],i);
  }

  logger::debug(String(AMOUNT_LEDS)+" led's have been set to pinmode(Output).");

  // Opens the first state
  openGameState(new StateWaitForStart);
}

void loop() {
  // Executes the tick event the open state
  currentState->onTick();

  // Updates the buttons
  triggerButton.onTick();
  switchButton.onTick();
}
