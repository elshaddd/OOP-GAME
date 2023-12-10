#include "SelectLevel.h"

SelectLevelCommand::SelectLevelCommand(IGame *game, int level) : game(game), level(level) {}

void SelectLevelCommand::execute()
{
    game->selectLevel(level);
}

std::vector<Status> SelectLevelCommand::getValidation()
{
    return std::vector<Status> {SELECTING};
}
