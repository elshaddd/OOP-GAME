#include "GameObserver.h"

GameObserver::GameObserver(Game *model, Display *display) : model(model), display(display)
{

    model->attach(this);
}

// Game *GameObserver::getSubject()
// {
//     return model;
// }

// Display *GameObserver::getDisplay()
// {
//     return display;
// }

void GameObserver::update()
{
    switch (model->getStatus())
    {
    case MENU:
        display->displayMenu();
        break;
    case SELECTING:
        display->displaySelecting();
        break;
    case PAUSE:
        display->displayPause();
        break;
    case WIN:
        display->displayWin();
        break;
    }
}