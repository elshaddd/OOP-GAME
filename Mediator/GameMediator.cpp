#include "GameMediator.h"

GameMediator::GameMediator(Game *gameModel, PlayerController *controllerModel, Display *display) : gameModel(gameModel), controllerModel(controllerModel), display(display){
    gameModel->setMediator(this);
    controllerModel->setMediator(this);
}

void GameMediator::update(Components component){
    if (component == GAME){
        switch (gameModel->getStatus()){
            
            case MENU:
                display->displayMenu();
                break;
            case SELECTING:
                display->displaySelecting();
                break;
            case WIN:
                display->displayWin();
                break;
            case PAUSE:
                display->displayPause();
                break;
            case OVER:
                display->displayOver();
                break;
            case RUN:
                display->displayRun();
                break;
        }
    }
    else if (component == MOVEMENT){
        if(gameModel->getStatus() == RUN)
            display->displayRun();
    }
}