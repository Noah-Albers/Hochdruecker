#pragma once
#include "../State.h"
#include "util/Timer.h"

class StateWaitForStart : public State{
    private:
        // Timer to update every few ms (not to frequently)
        Timer animationTimer;
    public:
        StateWaitForStart();
        void onTriggerButtonPressed();
        void onTick();
};