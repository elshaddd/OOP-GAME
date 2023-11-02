#ifndef MOVE_UP_COMMAND_H
#define MOVE_UP_COMMAND_H
#include "../Command.h"
#include "../../../Control/IMove.h"

class MoveUpCommand : public Command
{
private:
    IMove *controller;

public:
    MoveUpCommand(IMove *controller);
    void execute() override;
    // Command *clone() override;
};

#endif