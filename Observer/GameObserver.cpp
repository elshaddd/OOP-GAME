#include "GameObserver.h"

GameObserver::GameObserver(Game *model, Display *display) : model(model), display(display)
{

    model->attach(this);
}

Game *GameObserver::getSubject()
{
    return model;
}

Display *GameObserver::getDisplay()
{
    return display;
}

void GameObserver::update()
{
    switch (getSubject()->getStatus())
        {
        case MENU:
            getDisplay()->displayMenu();
            break;
        case SELECTING:
            getDisplay()->displaySelecting();
            break;
        case PAUSE:
            getDisplay()->displayPause();
            break;
        case WIN:
            getDisplay()->displayWin();
        }
}