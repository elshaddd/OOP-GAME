#ifndef GAME_H
#define GAME_H
#include <sstream>
#include "../Player/Player.h"
#include "../Field/Field.h"
#include "../Control/PlayerController.h"
#include "../Generators/FieldGenerator.h"

class Game
{
private:
    GameField &gameField;
    Player &player;
    PlayerController &controller;
    int level = 1;
    Status gameStatus = PAUSE;

public:
    Game(Player &player, GameField &gameField, PlayerController &controller);

    void leveling();

    void start();

    void restart();

    void selectLevel(int level);
    
    void quit();

    void nextLevel();

    void reset();

    void checkRun();

    Status getStatus();

    void setStatus(Status newStatus);

    int getLevel();

    void setLevel(int newLevel);
};

#endif