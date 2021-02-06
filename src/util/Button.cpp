#include "Button.h"
#include <Arduino.h>
#include "CompileConfig.h"
#include "Logger.h"

Button::Button(int gpioPin,void (*onPress)()){
    this->gpioPin=gpioPin;
    this->onPress=onPress;

    // Sets the actual pin mode
    pinMode(gpioPin,INPUT_PULLDOWN);

    logger::debug("Button with pin "+String(gpioPin)+" set to PULLDOWN.");
}

void Button::onTick(){
    // Gets the real button state
    bool pressed = digitalRead(this->gpioPin);

    // Checks if the state is different
    if(pressed == this->pressed){
        // Resets the timer
        this->timer=-1;
        return;
    }
    
    // Checks if the timer has begun to count
    if(this->timer == -1){
        this->timer=millis();
        return;
    }

    // Checks if the timer has reached the trigger time
    if(millis()-this->timer > BUTTON_TRIGGER_TIME){
        // Stops the timer
        this->timer=-1;

        // Updates the state
        this->pressed=pressed;

        logger::debug("Button at "+String(this->gpioPin)+" triggered to: "+String(pressed));

        // Checks if the change is a press
        if(pressed)
            // Executes the event handler
            this->onPress();
    }


}