#pragma once

/**
 * Class to access the pulldown button.
 */
class Button{
    private:
        // The gpiopin
        int gpioPin;

        // The callback handler for when the button gets pressed
        void (*onPress)();

        // If the button gets counted as pressed
        bool pressed;

        // How long the physical button had a different state
        // If the state is equal this is -1
        long timer = -1; //ms

    public:
        /**
         * @param gpioPin the pin on the physical board that will be used
         *                to listen for the button
         * 
         * @param onPress callback that will be called, when the button gets pressed
         */
        Button(int gpioPin,void (*onPress)());

        // Handler to update the button state. Should be called as fequently as possible
        // Calls the onPress function, when the button gets pressed
        void onTick();
};