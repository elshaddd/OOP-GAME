#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "Enums.h"
#include "Player.h"
#include "Field.h"
#include <utility>

class PlayerController
{
private:
    Player &playerRef;
    GameField &gameFieldRef;
    std::pair<int, int> coordinates;

public:
    PlayerController(Player &player, GameField &gameField);
    void movePlayer(Direction direction);

    void modifyHealth(int value);
    void modifyScore(int points);
    void modifyDamage(int value);

    std::pair<int,int> getCoordinates();
};

#endif