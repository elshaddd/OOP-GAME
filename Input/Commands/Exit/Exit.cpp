#include "Exit.h"

ExitCommand::ExitCommand(IGame *game) : game(game) {}

void ExitCommand::execute()
{
    game->exit();
}

// Command *ExitCommand::clone()
// {
//     return new ExitCommand(*this);
// }