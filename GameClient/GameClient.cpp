#include "GameClient.h"

GameClient::GameClient(MessageDispatcher *dispatcher, InputSource *inputSource): player(), gameField(), controller(player, gameField), game(player, gameField, controller, dispatcher), inputHandler(&controller, &game, *inputSource), display(player, gameField, controller), invoker(dispatcher) {}

void GameClient::loop()
{
    display.displayMenu();
    GameMediator mediator(&game, &controller, &display);
    while (game.getStatus() != EXIT)
    {
        invoker.call(inputHandler.handleInput());
        game.updateStatus();
    }
}