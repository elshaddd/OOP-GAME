#ifndef PLAYER_CONTROLLER_OBSERVER_H
#define PLAYER_CONTROLLER_OBSERVER_H
#include "../Control/PlayerController.h"
#include "../Util/Display.h"
// #include <utility>

class PlayerControllerObserver
{
private:
    PlayerController *model;
    Display display;

public:
    PlayerControllerObserver(PlayerController *model, Display display);

    void update();

    PlayerController *getSubject();
    
};

#endif