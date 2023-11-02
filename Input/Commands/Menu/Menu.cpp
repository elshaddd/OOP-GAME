#include "Menu.h"

MenuCommand::MenuCommand(IGame *game) : game(game) {}

void MenuCommand::execute()
{
    game->menu();
}