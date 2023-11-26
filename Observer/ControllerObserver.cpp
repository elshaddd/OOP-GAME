#include "ControllerObserver.h"

PlayerControllerObserver::PlayerControllerObserver(PlayerController *model, Display *display) : model(model), display(display)
{
    model->attach(this);
}

PlayerController *PlayerControllerObserver::getSubject()
{
    return model;
}

Display *PlayerControllerObserver::getDisplay()
{
    return display;
}

void PlayerControllerObserver::update()
{
    if (getSubject()->playerRef.getHealth() == 0)
    {
        getDisplay()->displayOver();
        return;
    }
    getDisplay()->displayRun();
}