#pragma once
#include "../State.h"

class StateWin : public State{
    public:
        StateWin();
        void onTick();
        void onStateOpen();
};