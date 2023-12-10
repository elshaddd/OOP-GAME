#include "GameClient.h"

GameClient::GameClient(MessageDispatcher *dispatcher, InputSource *inputSource) : player(20), gameField(), controller(player, gameField), game(player, gameField, controller, dispatcher), inputHandler(&controller, &game, *inputSource), display(player, gameField, controller), invoker(dispatcher) {}

void GameClient::loop()
{
    display.displayMenu();
    GameMediator mediator(&game, &controller, &display);
    while (game.getStatus() != EXIT)
    {
        std::pair<char, Command *> pair = inputHandler.handleInput();

        if (pair.second)
        {
            if (checkValidation(pair.second->getValidation()))
                invoker.call(pair);
        }
        else
        {
            invoker.call(pair);
        }
        game.updateStatus();
    }
}

bool GameClient::checkValidation(std::vector<Status> vector)
{
    for (const auto &element : vector)
    {
        if (element == game.getStatus())
        {
            return true;
        }
    }
    return false;
}