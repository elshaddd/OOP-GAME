#ifndef MOVE_RIGHT_COMMAND_H
#define MOVE_RIGHT_COMMAND_H
#include "../Command.h"
#include "../../../Control/IMove.h"

class MoveRightCommand : public Command
{
private:
    IMove *controller;

public:
    MoveRightCommand(IMove *controller);
    void execute() override;
    // Command *clone() override;
};

#endif