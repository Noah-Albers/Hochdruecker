#pragma once
#include "gamestate/State.h"

// Holds the pins on which the leds are connected
extern char LED_PINS[5];
// How many leds are connected
extern int AMOUNT_LEDS;

// The pins for the buttons (switch and trigger)
extern int BUTTON_PIN_SWITCH;
extern int BUTTON_PIN_TRIGGER;

// Holds the currently opened state. Should only be modifed by @openGameState
extern State* currentState;

// If the difficulty is in easy mode
extern bool diffcultyEasy;

/**
 * Closes a previously opend state and opens the new state
 * @param state the Pointer to the new state. Will be delete automatically when the next state opens.
 *              As the pointer could be deleted anytime (Mainly by the state itself), it sould not be depended up on or stored at other locations.
 */
void openGameState(State* state);
