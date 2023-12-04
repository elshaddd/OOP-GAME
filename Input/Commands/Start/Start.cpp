#include "Start.h"

StartCommand::StartCommand(IGame *game) : game(game) {}

void StartCommand::execute()
{
    game->start();
}

std::vector<Status> StartCommand::getValidation()
{
    return std::vector<Status> {MENU};
}
