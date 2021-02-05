#pragma once
#include "../State.h"

class StateLoss : public State{
    public:
        StateLoss();
        void onTick();
        void onStateOpen();
};