#ifndef QUIT_COMMAND_H
#define QUIT_COMMAND_H
#include "../Command.h"
#include <functional>
#include "../../../Game/IGame.h"

class QuitCommand : public Command
{
private:
    IGame *game;
    
public:
    QuitCommand(IGame *game);

    void execute() override;
};

#endif