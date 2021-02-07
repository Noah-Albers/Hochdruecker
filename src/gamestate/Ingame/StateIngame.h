#pragma once
#include "../State.h"
#include "util/Timer.h"

class StateIngame : public State{
    private:
        // On which stage the player is on
        int currentStage=1;

        // If the correct led is blinking
        bool winLedEnabled=false;

        // The timer to measure the blink timing
        Timer blinkTimer;

        // Returns the ledc-Channel of the led that is currently high
        char getCurrentLedChannel();

        // Switches the led that is currently high 
        void switchLed();
    public:
        StateIngame();
        void onStateOpen();
        void onTriggerButtonPressed();
        void onTick();
};