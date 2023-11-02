#include "SelectLevel.h"

SelectLevelCommand::SelectLevelCommand(IGame *game, int level) : game(game), level(level) {}

void SelectLevelCommand::execute()
{
    game->selectLevel(level);
}