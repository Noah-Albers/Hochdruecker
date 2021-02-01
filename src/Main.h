#pragma once
#include "gamestate/State.h"

// Holds the currently opened state. Should only be modifed by @openGameState
extern State* currentState;

/**
 * Closes a previously opend state and opens the new state
 * @param state the Pointer to the new state. Will be delete automatically when the next state opens.
 *              As the pointer could be deleted anytime (Mainly by the state itself), it sould not be depended up on or stored at other locations.
 */
void openGameState(State* state);
