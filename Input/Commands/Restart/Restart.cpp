#include "Restart.h"
#include "../../../Game/Game.h"

RestartCommand::RestartCommand(Game &game) : game(game) {}

void RestartCommand::execute()
{
    game.restart();
}