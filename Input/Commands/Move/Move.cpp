#include "Move.h"

MoveCommand::MoveCommand(IMove *controller, Direction direction) : controller(controller), direction(direction) {}

void MoveCommand::execute()
{
    controller->movePlayer(direction);
}