#include "Select.h"

SelectCommand::SelectCommand(IGame *game) : game(game) {}

void SelectCommand::execute()
{
    game->select();
}