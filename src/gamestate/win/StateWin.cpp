#include "StateWin.h"
#include "Main.h"
#include "Logger.h"
#include "CompileConfig.h"
#include "gamestate/waitForStart/StateWaitForStart.h"

StateWin::StateWin() : State("Win"){}

void StateWin::onStateOpen(){
    this->clearLeds();
}

void StateWin::clearLeds(){
    // Disables all leds
    for(int i=0;i<AMOUNT_LEDS;i++)
        ledcWrite(i,0);
}

long StateWin::getPlayTime(){
    return this->animationTimes[this->animationStage]; //ms
}

void StateWin::onTick(){

    // Checks if the timer has reached the current stages limit
    if(this->stageTimer.hasReached(this->getPlayTime())){
        // Resets the timer
        this->stageTimer.reset();
        // Starts the next stage
        this->animationStage++;
        // Resets the seperate animation variables
        this->t2.reset();
        this->i2=0;
        // Clears all leds
        this->clearLeds();

        logger::debug("(Win) Opening next animationstate: "+String(this->animationStage));
    }

    // Checks the animation stage
    switch(this->animationStage){
        case 1:
            this->animateStageOne();
            break;
        case 2: case 3: case 4:
            this->animateStageTwo();
            break;
        case 6:
            // Opens the waiting state again
            openGameState(new StateWaitForStart);
            break;
    }
}

void StateWin::animateStageOne(){
    // Gets a slower version of the time variable
    long time = millis()/300;

    for(int i=0;i<5;i++)
        // Animates a blining that moves over all lamps
        ledcWrite(i,(time+i) % 2 == 0 ? 0 : 255);
}

void StateWin::animateStageTwo(){
    // Gets the time of one iteration per led
    int time = (this->getPlayTime()*.8)/AMOUNT_LEDS;

    // Checks if the timer has reached that limit
    if(this->t2.hasReached(time)){
        this->t2.reset();

        // Lights up the current led
        ledcWrite(this->i2,100); 

        // Increments to the next led
        this->i2++;
    }
}