#ifndef GAME_MEDIATOR_H
#define GAME_MEDIATOR_H
#include "../Game/Game.h"
#include "../Util/Display.h"
#include "Mediator.h"

class GameMediator : public Mediator{
    Game *gameModel;
    PlayerController *controllerModel;
    Display *display;

public:
    GameMediator(Game *gameModel, PlayerController *controllerModel, Display *display);

    void update(Components component) override;
};

#endif