#ifndef GAME_CLIENT_H
#define GAME_CLIENT_H
#include <sstream>
#include "../Game/Game.h"
#include "../Input/InputHandler/InputHandler.h"
#include "../Invoker/Invoker.h"
#include "../Input/InputSource/InputSource.h"
#include "../Input/InputSource/ConsoleInputSource/ConsoleInputSource.h"
#include "../Util/Display.h"

class GameClient
{
private:
    Player player;
    GameField gameField;
    PlayerController controller;
    Game game;
    InputHandler inputHandler;
    Display display;

public:
    GameClient(InputSource *inputSource = new ConsoleInputSource);

    void loop();

    // void displayMenu();

    // void displaySelecting();

    // void displayPause();

    // void displayRun();

    // void displayOver();
};

#endif