#ifndef RESTART_COMMAND_H
#define RESTART_COMMAND_H
#include "../Command.h"
#include <functional>
#include "../../../Game/IGame.h"

class RestartCommand : public Command
{
private:
    IGame *game;
    
public:
    RestartCommand(IGame *game);

    void execute() override;

    std::vector<Status> getValidation() override;
};

#endif