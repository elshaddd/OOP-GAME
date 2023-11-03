#ifndef GAME_H
#define GAME_H
#include <sstream>
#include "IGame.h"
#include "../Player/Player.h"
#include "../Field/Field.h"
#include "../Control/PlayerController.h"
#include "../Generators/FieldGenerator.h"

class Game : public IGame
{
private:
    GameField &gameField;
    Player &player;
    PlayerController &controller;
    int level = 1;
    Status gameStatus = MENU;

public:
    Game(Player &player, GameField &gameField, PlayerController &controller);

    void leveling();

    //
    void start() override;

    void restart() override;

    void select() override;

    void selectLevel(int level) override;

    void quit() override;

    void menu() override;

    void exit() override;
    //

    void nextLevel();

    void reset();

    void checkRun();

    Status getStatus();

    void setStatus(Status newStatus);
};

#endif