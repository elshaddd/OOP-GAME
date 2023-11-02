#include "Start.h"

StartCommand::StartCommand(IGame *game) : game(game) {}

void StartCommand::execute()
{
    game->start();
}