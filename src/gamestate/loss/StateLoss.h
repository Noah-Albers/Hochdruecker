#pragma once
#include "../State.h"
#include "util/Timer.h"

class StateLoss : public State{
    private:
        // Timer for the animation
        Timer timer;
        // The next led that should turn off
        int nextLed=0;
    public:
        StateLoss();
        void onTick();
        void onStateOpen();
};