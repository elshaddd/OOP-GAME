#ifndef SELECT_LEVEL_COMMAND_H
#define SELECT_LEVEL_COMMAND_H
#include "../Command.h"
#include <functional>
#include "../../../Game/IGame.h"

class SelectLevelCommand : public Command
{
private:
    IGame *game;
    int level;

public:
    SelectLevelCommand(IGame *game, int level);

    void execute() override;

    std::vector<Status> getValidation() override;
};

#endif