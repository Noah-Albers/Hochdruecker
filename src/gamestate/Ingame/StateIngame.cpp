#include "StateIngame.h"
#include "Logger.h"
#include "CompileConfig.h"
#include "Main.h"
#include <Arduino.h>
#include "gamestate/win/StateWin.h"
#include "gamestate/loss/StateLoss.h"

StateIngame::StateIngame() : State("Ingame") {}

void StateIngame::onStateOpen(){
    clearLeds();
}

char StateIngame::getCurrentLedChannel(){
    return this->winLedEnabled?this->currentStage:0;
}

void StateIngame::switchLed(){
    // Disables the current led
    ledcWrite(this->getCurrentLedChannel(),0);

    // Updates the led enable
    this->winLedEnabled=!this->winLedEnabled;

    // Enables the new led
    ledcWrite(this->getCurrentLedChannel(),255);

    logger::trace("Led switched to "+String(this->winLedEnabled==1?"win":"loss"));
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

        logger::trace("Timer triggert");
    }
}

void StateIngame::onTriggerButtonPressed(){
    // Disables the current led
    ledcWrite(this->getCurrentLedChannel(),0);

    // Checks if the player pressed at the wrong led
    if(!this->winLedEnabled){
        // Opens the loss stage
        openGameState(new StateLoss);
        return;
    }

    // Checks if the player has won
    if(this->currentStage == AMOUNT_LEDS-1){
        // Opens the win stage
        openGameState(new StateWin);
        return;
    }

    // Increases the players stage
    this->currentStage++;

    logger::debug("Clicked on "+String(this->winLedEnabled?"win":"loss")+"-state. New stage: "+String(this->currentStage));

    // Resets the timer
    this->blinkTimer.reset();

    // Shows the next led
    this->winLedEnabled=true;

    // Enables the current led
    ledcWrite(this->getCurrentLedChannel(),255);
}