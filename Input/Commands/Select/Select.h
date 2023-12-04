#ifndef SELECT_COMMAND_H
#define SELECT_COMMAND_H
#include "../Command.h"
#include <functional>
#include "../../../Game/IGame.h"

class SelectCommand : public Command
{
private:
    IGame *game;

public:
    SelectCommand(IGame *game);

    void execute() override;

    std::vector<Status> getValidation() override;
};

#endif