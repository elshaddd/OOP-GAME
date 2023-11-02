#ifndef MOVE_DOWN_COMMAND_H
#define MOVE_DOWN_COMMAND_H
#include "../Command.h"
#include "../../../Control/IMove.h"

class MoveDownCommand : public Command
{
private:
    IMove *controller;

public:
    MoveDownCommand(IMove *controller);
    void execute() override;
    // Command *clone() override;
};

#endif