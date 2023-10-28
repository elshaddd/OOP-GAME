#ifndef MOVE_UP_COMMAND_H
#define MOVE_UP_COMMAND_H
#include "../Command.h"

class MoveUpCommand : public Command
{
private:
    PlayerController &controller;

public:
    MoveUpCommand(PlayerController &controller);
    void execute() override;
};

#endif