#ifndef PLAYER_CONTROLLER_OBSERVER_H
#define PLAYER_CONTROLLER_OBSERVER_H
#include "../Control/PlayerController.h"
#include "../Util/Display.h"
#include "IControllerObserver.h"

class PlayerControllerObserver : public IControllerObserver
{
    PlayerController *model;
    Display *display;

public:
    PlayerControllerObserver(PlayerController *model, Display *display);

    void update() override;

    // PlayerController *getSubject() override;

    // Display *getDisplay() override;
};

#endif