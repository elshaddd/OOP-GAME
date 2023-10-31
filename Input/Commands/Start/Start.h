#ifndef START_COMMAND_H
#define START_COMMAND_H
#include "../Command.h"
#include <functional>

class StartCommand : public Command
{
private:
    Game &game;

public:
    StartCommand(Game &game);

    void execute() override;
};

#endif