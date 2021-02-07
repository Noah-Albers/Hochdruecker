#include "StateLoss.h"
#include "Main.h"
#include "CompileConfig.h"
#include "gamestate/waitForStart/StateWaitForStart.h"
#include "Logger.h"

StateLoss::StateLoss() : State("Loss"){}

void StateLoss::onStateOpen(){
    // Enables all leds
    for(int i=0;i<AMOUNT_LEDS; i++)
        ledcWrite(i,100);
    
    logger::debug("All leds have been enabled.");
}

void StateLoss::onTick(){

    // Gets the time of one iteration per led
    int time = 3000/AMOUNT_LEDS;

    // Checks if the timer has reached that limit
    if(this->timer.hasReached(time)){
        this->timer.reset();
        
        logger::debug("Triggering the disable of the next led: "+String(this->nextLed));

        // Checks if the next led is outside of the scope
        if(this->nextLed > AMOUNT_LEDS){
            // Goes again into the wait state
            openGameState(new StateWaitForStart);
            return;
        }

        // Lights up the current led
        ledcWrite(this->nextLed++,0); 
    }
}
