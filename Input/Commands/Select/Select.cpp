#include "Select.h"

SelectCommand::SelectCommand(IGame *game) : game(game) {}

void SelectCommand::execute()
{
    game->select();
}

std::vector<Status> SelectCommand::getValidation()
{
    return std::vector<Status> {MENU};
}
