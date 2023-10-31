#ifndef RESTART_COMMAND_H
#define RESTART_COMMAND_H
#include "../Command.h"
#include <functional>

class RestartCommand : public Command
{
private:
    Game &game;
    
public:
    RestartCommand(Game &game);

    void execute() override;
};

#endif