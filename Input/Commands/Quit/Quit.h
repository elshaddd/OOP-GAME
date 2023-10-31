#ifndef QUIT_COMMAND_H
#define QUIT_COMMAND_H
#include "../Command.h"
#include <functional>

class QuitCommand : public Command
{
private:
    Game &game;
    
public:
    QuitCommand(Game &game);

    void execute() override;
};

#endif