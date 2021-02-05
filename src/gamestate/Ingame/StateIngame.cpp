#include "StateIngame.h"
#include "Logger.h"
#include "Main.h"
#include <Arduino.h>
#include "gamestate/win/StateWin.h"
#include "gamestate/loss/StateLoss.h"

char StateIngame::getCurrentLedPin(){
    return LED_PINS[this->winLedEnabled?this->currentStage:0];
}

void StateIngame::switchLed(){
    // Disables the current led
    digitalWrite(this->getCurrentLedPin(),LOW);

    // Updates the led enable
    this->winLedEnabled=!this->winLedEnabled;

    // Enables the new led
    digitalWrite(this->getCurrentLedPin(),HIGH);
}

void StateIngame::onTick(){
    // Gets how long the timer has to wait
    long time = (
        (float)1/(float)(
            diffcultyEasy?
                this->currentStage:
                this->winLedEnabled?this->currentStage:1
        )
    )*1000;

    // Ensures that the time doesn't got lower than 0,2s
    if(time<200)
        time=200;

    // Checks if the timer has already reached that limit
    if(this->blinkTimer.hasReached(time)){
        // Resets the timer
        this->blinkTimer.reset();

        // Switches the led
        this->switchLed();
    }
}

void StateIngame::onTriggerButtonPressed(){
    // Disables the current led
    digitalWrite(this->getCurrentLedPin(),LOW);

    // Checks if the player has lost or won
    if(this->currentStage == (this->winLedEnabled?AMOUNT_LEDS:1)){
        // Checks which state should be opened next
        if(this->winLedEnabled)
            // Opens the win state
            openGameState(new StateWin);
        else
            // Opens the loss state
            openGameState(new StateLoss);
        return;
    }else
        // In/Decreases the stage depending if the player has won
        this->currentStage+=this->winLedEnabled?1:-1;

    // Resets the timer
    this->blinkTimer.reset();

    // Resets the win led
    this->winLedEnabled=false;

    // Enables the current led
    digitalWrite(this->getCurrentLedPin(),HIGH);
}