#pragma once
#include "../State.h"
#include "util/Timer.h"

class StateIngame : public State{
    private:
        // On which stage the player is on
        int currentStage=0;

        // If the correct led is blinking
        bool winLedEnabled;

        // The timer to measure the blink timing
        Timer blinkTimer;

        // Returns the GPIO-Pin of the led that is currently high
        char getCurrentLedPin();
        
        // Switches the led that is currently high 
        void switchLed();
    public:
        void onTriggerButtonPressed();
        void onTick();
};