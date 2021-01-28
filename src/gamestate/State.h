#pragma once

class State{
    public:
        virtual ~State();

        // Gets executed when the button for trigger
        // gets pressed
        virtual void onTriggerButtonPressed();
        
        // Gets executed when the button for
        // switching the difficulty gets pressed
        virtual void onSwitchButtonPressed();

        // Tick event that fires constantly
        virtual void onTick();
};