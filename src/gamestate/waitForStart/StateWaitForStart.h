#pragma once
#include "../State.h"

class StateWaitForStart : public State{
    public:
        void onTriggerButtonPressed();
};