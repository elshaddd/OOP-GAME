#ifndef START_COMMAND_H
#define START_COMMAND_H
#include "../Command.h"
#include <functional>
#include "../../../Game/IGame.h"

class StartCommand : public Command
{
private:
    IGame *game;

public:
    StartCommand(IGame *game);

    void execute() override;
};

#endif