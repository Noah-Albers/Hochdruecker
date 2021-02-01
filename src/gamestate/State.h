#pragma once

class State{
    public:
        virtual ~State();

        // Executes when the state gets closed
        virtual void onStateClose();

        // Executes when the state opens
        virtual void onStateOpen();

        // Tick event that fires constantly
        virtual void onTick();
        
        // Gets executed when the button for trigger
        // gets pressed
        virtual void onTriggerButtonPressed();
        
        // Gets executed when the button for
        // switching the difficulty gets pressed
        virtual void onSwitchButtonPressed();


};