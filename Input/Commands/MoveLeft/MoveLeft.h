#ifndef MOVE_LEFT_COMMAND_H
#define MOVE_LEFT_COMMAND_H
#include "../Command.h"
#include "../../../Control/IMove.h"

class MoveLeftCommand : public Command
{
private:
    IMove *controller;

public:
    MoveLeftCommand(IMove *controller);
    void execute() override;
    // Command *clone() override;
};

#endif