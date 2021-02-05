#pragma once
#include "../State.h"

class StateLoss : public State{
    public:
        void onTick();
        void onStateOpen();
};