#include "Restart.h"

RestartCommand::RestartCommand(IGame *game) : game(game) {}

void RestartCommand::execute()
{
    game->restart();
}