#include "MoveLeft.h"

MoveLeftCommand::MoveLeftCommand(IMove *controller) : controller(controller) {}

void MoveLeftCommand::execute()
{
    controller->movePlayer(Direction::LEFT);
}

// Command *MoveLeftCommand::clone()
// {
//     return new MoveLeftCommand(*this);
// }