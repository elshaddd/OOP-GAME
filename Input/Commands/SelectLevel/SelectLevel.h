#ifndef SELECT_LEVEL_COMMAND_H
#define SELECT_LEVEL_COMMAND_H
#include "../Command.h"
#include <functional>

class SelectLevelCommand : public Command
{
private:
    Game &game;
    int level;

public:
    SelectLevelCommand(Game &game, int level);

    void execute() override;
};

#endif