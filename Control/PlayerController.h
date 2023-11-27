#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H
#include "IMove.h"
#include "../Player/Player.h"
#include "../Field/Field.h"
#include "../Observer/IControllerObserver.h"
#include <utility>
#include <vector>

class PlayerController : public IMove
{
private:
    GameField &gameFieldRef;
    std::pair<int, int> coordinates;

    IControllerObserver *view;

public:
    Player &playerRef;

    PlayerController(Player &player, GameField &gameField);

    void movePlayer(Direction direction) override;

    void modifyHealth(int value);

    void modifyScore(int points);

    // void modifyDamage(int value);

    void setCoordinates(std::pair<int, int> coords);

    std::pair<int, int> getCoordinates();

    void attach(IControllerObserver *obs);

    void notify();

    // PlayerController(const PlayerController &other);

    // PlayerController &operator=(const PlayerController &other);
};

#endif