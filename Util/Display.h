#ifndef DISPLAY_H
#define DISPLAY_H
#include <sstream>
#include <iostream>
#include "../Control/PlayerController.h"
#include "../Field/Field.h"
#include "../Player/Player.h"
#include "../Events/Visitor/EventSymbolVisitor.h"

class Display
{
private:
    Player &player;
    GameField &gameField;
    PlayerController &controller;

public:
    Display(Player &player, GameField &gameField, PlayerController &controller);

    void displayMenu();

    void displaySelecting();

    void displayPause();

    void displayRun();

    void displayOver();

    void displayWin();
};

#endif