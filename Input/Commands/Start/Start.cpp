#include "Start.h"
#include "../../../Game/Game.h"

StartCommand::StartCommand(Game &game) : game(game) {}

void StartCommand::execute()
{
    game.start();
}