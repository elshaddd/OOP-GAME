#include "Quit.h"

QuitCommand::QuitCommand(IGame *game) : game(game) {}

void QuitCommand::execute()
{
    game->quit();
}

std::vector<Status> QuitCommand::getValidation()
{
    return std::vector<Status> {PAUSE, RUN, WIN, SELECTING};
}
