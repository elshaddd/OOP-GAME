#include "GameClient.h"

GameClient::GameClient(MessageDispatcher *dispatcher, InputSource *inputSource): player(), gameField(), controller(player, gameField), game(player, gameField, controller, dispatcher), inputHandler(&controller, &game, *inputSource, dispatcher), display(player, gameField, controller) {}

void GameClient::loop()
{
    display.displayMenu();
    Invoker invoker;
    GameMediator mediator(&game, &controller, &display);
    while (game.getStatus() != EXIT)
    {
        invoker.call(inputHandler.handleInput());
        game.updateStatus();
    }
}