#include "StateWaitForStart.h"
#include "Main.h"
#include "gamestate/ingame/StateIngame.h"
#include "CompileConfig.h"
#include "Logger.h"

StateWaitForStart::StateWaitForStart() : State("WaitForStart"){}

void StateWaitForStart::onTriggerButtonPressed(){
    openGameState(new StateIngame);
}

void StateWaitForStart::onTick(){
    // Checks if the timer is ready
    if(!this->animationTimer.hasReached(50))
        return;
    
    // Resets the timer
    this->animationTimer.reset();

    // Time it takes for the animation to complete
    int duration = 2000; //ms
    // The max ledc value for the leds
    int max = 20;
    // The min ledc value fro the leds
    int min = 6;

    // Updates every led
    for(int i=0;i<AMOUNT_LEDS;i++){
        // Calculates the percentage value of the current iteration.
        float perc = (float)((millis()+(duration/AMOUNT_LEDS)*i) %(duration))/ (float)duration;

        // Maps the percentage value to a scale that goes from 0 to 1 and back from 1 to 0
        float half = (perc < .5 ? perc : (1-perc)) * 2;

        // Calcualtes the actual ledc value from the max and min
        int betwen = half*max + min;

        // Updates the led
        ledcWrite(i,betwen);
    }
}