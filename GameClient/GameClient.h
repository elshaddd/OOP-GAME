#ifndef GAME_CLIENT_H
#define GAME_CLIENT_H
#include <sstream>
#include "../Game/Game.h"
#include "../Input/InputHandler/InputHandler.h"
#include "../Invoker/Invoker.h"
#include "../Input/InputSource/InputSource.h"
#include "../Input/InputSource/ConsoleInputSource/ConsoleInputSource.h"
#include "../Events/Visitor/EventSymbolVisitor.h"

class GameClient
{
private:
    Player player;
    GameField gameField;
    PlayerController controller;
    Game game;
    InputHandler inputHandler;

public:

    GameClient(InputSource *inputSource = new ConsoleInputSource);
    
    void loop();
    
    void displayMenu();
    
    void display();

    void displayOver();
};

#endif