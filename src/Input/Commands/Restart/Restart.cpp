#include "Restart.h"

RestartCommand::RestartCommand(IGame *game) : game(game) {}

void RestartCommand::execute()
{
    game->restart();
}

std::vector<Status> RestartCommand::getValidation()
{
    return std::vector<Status> {PAUSE, OVER, WIN};
}
