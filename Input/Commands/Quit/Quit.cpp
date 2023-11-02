#include "Quit.h"

QuitCommand::QuitCommand(IGame *game) : game(game) {}

void QuitCommand::execute()
{
    game->quit();
}