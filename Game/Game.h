#ifndef GAME_H
#define GAME_H
#include <sstream>
#include "../Player/Player.h"
#include "../Field/Field.h"
#include "../Util/Enums.h"
#include "../Control/PlayerController.h"
#include "../Input/InputHandler/InputHandler.h"
#include "../Input/InputSource/InputSource.h"
#include "../Generators/FieldGenerator.h"
#include "../Events/Visitor/EventSymbolVisitor.h"

class Game
{
private:
    GameField gameField;
    Player player;
    PlayerController controller;
    InputHandler inputHandler;
    int level = 1;
    Status gameStatus = PAUSE;

public:
    Game(InputSource *inputSource);

    void process();

    void gameLoop();

    void leveling();

    void start();

    void restart();

    void selectLevel(int level);

    void quit();

    void checkRun();

    void gameOver();

    void display();

    void displayMenu();

    void displayOver();

    void displayPass();
};

#endif