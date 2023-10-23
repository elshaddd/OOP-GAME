#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H

#include "../Util/Enums.h"
#include "../Player/Player.h"
#include "../Field/Field.h"
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

    void setCoordinates(std::pair<int, int> coords);
    std::pair<int,int> getCoordinates();
};

#endif