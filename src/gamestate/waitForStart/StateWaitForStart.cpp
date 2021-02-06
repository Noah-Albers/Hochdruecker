#include "StateWaitForStart.h"
#include "Main.h"
#include "gamestate/ingame/StateIngame.h"

StateWaitForStart::StateWaitForStart() : State("WaitForStart"){}

void StateWaitForStart::onTriggerButtonPressed(){
    openGameState(new StateIngame);
}