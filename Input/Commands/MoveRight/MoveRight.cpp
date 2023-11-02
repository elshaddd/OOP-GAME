#include "MoveRight.h"

MoveRightCommand::MoveRightCommand(IMove *controller) : controller(controller) {}

void MoveRightCommand::execute()
{
    controller->movePlayer(Direction::RIGHT);
}

// Command *MoveRightCommand::clone()
// {
//     return new MoveRightCommand(*this);
// }