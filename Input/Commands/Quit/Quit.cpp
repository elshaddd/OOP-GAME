#include "Quit.h"
#include "../../../Game/Game.h"

QuitCommand::QuitCommand(Game &game) : game(game) {}

void QuitCommand::execute()
{
    game.quit();
}