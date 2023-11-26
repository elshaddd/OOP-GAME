#include "ControllerObserver.h"

PlayerControllerObserver::PlayerControllerObserver(PlayerController *model, Display display) : model(model), display(display)
{
    model->attach(this);
}
void PlayerControllerObserver::update()
{
    if (getSubject()->playerRef.getHealth() == 0)
    {
        display.displayOver();
        return;
    }
    display.displayRun();
}

PlayerController *PlayerControllerObserver::getSubject()
{
    return model;
}