#pragma once
#include "../State.h"

class StateWin : public State{
    public:
        void onTick();
        void onStateOpen();
};