#ifndef MOVE_DOWN_COMMAND_H
#define MOVE_DOWN_COMMAND_H
#include "../Command.h"

class MoveDownCommand : public Command
{
private:
    PlayerController &controller;

public:
    MoveDownCommand(PlayerController &controller);
    void execute() override;
};

#endif