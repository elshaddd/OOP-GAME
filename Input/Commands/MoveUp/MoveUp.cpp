#include "MoveUp.h"

MoveUpCommand::MoveUpCommand(IMove *controller) : controller(controller) {}

void MoveUpCommand::execute()
{
    controller->movePlayer(Direction::UP);
}

// Command *MoveUpCommand::clone()
// {
//     return new MoveUpCommand(*this);
// }