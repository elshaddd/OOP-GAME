#include "Menu.h"

MenuCommand::MenuCommand(IGame *game) : game(game) {}

void MenuCommand::execute()
{
    game->menu();
}

std::vector<Status> MenuCommand::getValidation()
{
    return std::vector<Status> {PAUSE, OVER, WIN};
}
