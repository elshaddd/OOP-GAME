#ifndef MOVE_COMMAND_H
#define MOVE_COMMAND_H
#include "../Command.h"
#include "../../../Control/IMove.h"

class MoveCommand : public Command
{
private:
    IMove *controller;
    Direction direction;

public:
    MoveCommand(IMove *controller, Direction direction);
    void execute() override;
    std::vector<Status> getValidation() override;
};

#endif