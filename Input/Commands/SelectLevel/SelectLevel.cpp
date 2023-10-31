#include "SelectLevel.h"
#include "../../../Game/Game.h"

SelectLevelCommand::SelectLevelCommand(Game &game, int level) : game(game), level(level) {}

void SelectLevelCommand::execute()
{
    game.selectLevel(level);
}