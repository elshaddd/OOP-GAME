#ifndef GAME_OBSERVER_H
#define GAME_OBSERVER_H
#include "../Game/Game.h"
#include "../Util/Display.h"
#include "IGameObserver.h"

class GameObserver : public IGameObserver
{
    Game *model;
    Display *display;
public:
    GameObserver(Game *model, Display *display);

    void update() override;

    Game *getSubject() override;

    Display *getDisplay() override;
};

#endif