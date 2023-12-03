#ifndef PLAYER_CONTROLLER_H
#define PLAYER_CONTROLLER_H
#include "IMove.h"
#include "../Player/Player.h"
#include "../Field/Field.h"
#include "../Mediator/Mediator.h"
#include "../Mediator/Component.h"
#include <utility>
#include <vector>

class PlayerController : public IMove, public Component
{
private:
    GameField &gameFieldRef;
    std::pair<int, int> coordinates;

    Mediator *mediator;

public:
    Player &playerRef;

    PlayerController(Player &player, GameField &gameField);

    void movePlayer(Direction direction) override;

    void modifyHealth(int value);

    void modifyScore(int points);

    // void modifyDamage(int value);

    void setCoordinates(std::pair<int, int> coords);

    std::pair<int, int> getCoordinates();

    void setMediator(Mediator *mediator) override;
    
    void notify() override;

    // PlayerController(const PlayerController &other);

    // PlayerController &operator=(const PlayerController &other);
};

#endif