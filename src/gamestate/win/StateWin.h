#pragma once
#include "../State.h"
#include "util/Timer.h"

class StateWin : public State{
    private:
        // Timer to help the animation
        Timer stageTimer;
        // The current stage of the animation
        int animationStage=0;
        // Holds the animation timings for all stages
        int animationTimes[7] = {2000,5000,2000,2000,2000,4000,0};

        /*
         *   Seperat animation variables
         */
        
        Timer t2;
        int i2;

    public:
        StateWin();
        void onTick();
        void onStateOpen();

        // Clears all leds
        void clearLeds();
        // Calculates the play-time of the current stage
        long getPlayTime();

        // The different animation stages
        void animateStageOne();
        void animateStageTwo();
};