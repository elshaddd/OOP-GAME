#ifndef MOVE_RIGHT_COMMAND_H
#define MOVE_RIGHT_COMMAND_H
#include "../Command.h"

class MoveRightCommand : public Command
{
private:
    PlayerController &controller;

public:
    MoveRightCommand(PlayerController &controller);
    void execute() override;
    // Command *clone() override;
};

#endif