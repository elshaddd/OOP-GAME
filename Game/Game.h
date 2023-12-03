#ifndef GAME_H
#define GAME_H
#include <sstream>
#include "IGame.h"
#include "../Player/Player.h"
#include "../Field/Field.h"
#include "../Control/PlayerController.h"
#include "../Generators/FieldGenerator.h"
#include "../Mediator/Component.h"
#include "../Mediator/Mediator.h"
#include "../Logging/Dispatcher/MessageDispatcher.h"
#include "../Logging/Message/Game/StartMessage.h"
#include "../Logging/Message/Player/WinMessage.h"
#include "../Logging/Message/PlayerController/LoseMessage.h"

class Game : public IGame, public Component
{
private:
    GameField &gameField;
    Player &player;
    PlayerController &controller;
    int level = 1;
    Status gameStatus = MENU;

    Mediator *mediator;
    MessageDispatcher *dispatcher;

public:
    Game(Player &player, GameField &gameField, PlayerController &controller, MessageDispatcher *dispatcher);

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

    void updateStatus();

    Status getStatus();

    void setStatus(Status newStatus);

    void setMediator(Mediator *mediator) override;
    
    void notify() override;
};

#endif