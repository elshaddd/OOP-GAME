#include "SelectLevel.h"

SelectLevelCommand::SelectLevelCommand(std::function<void(int)> selectLevelCallback, int level) : selectLevelCallback(selectLevelCallback), level(level) {}

void SelectLevelCommand::execute()
{
    selectLevelCallback(level);
}