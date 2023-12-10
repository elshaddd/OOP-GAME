#include "Exit.h"

ExitCommand::ExitCommand(IGame *game) : game(game) {}

void ExitCommand::execute()
{
    game->exit();
}

std::vector<Status> ExitCommand::getValidation()
{
    return std::vector<Status> {MENU};
}