#ifndef MOVE_LEFT_COMMAND_H
#define MOVE_LEFT_COMMAND_H
#include "../Command.h"

class MoveLeftCommand : public Command
{
private:
    PlayerController &controller;

public:
    MoveLeftCommand(PlayerController &controller);
    void execute() override;
};

#endif