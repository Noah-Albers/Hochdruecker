#pragma once

class Timer{
    public:
        Timer();

        /**
         * Resets the last timestamp to the current time. Basically resetting the timer 
         */
        void reset();

        /**
         * Returns if passed time is above or at the given time in milliseconds.
         * @param timeInMs the time in milliseconds that the timer has to be over
         */
        bool hasReached(long timeInMs);

        /**
         * Returns the difference between the last time and the current time in milliseconds. 
         */
        long getTimeDifference();
    private:
        long timeStamp;
};