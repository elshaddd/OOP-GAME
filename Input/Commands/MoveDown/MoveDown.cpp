#include "MoveDown.h"

MoveDownCommand::MoveDownCommand(IMove *controller) : controller(controller) {}

void MoveDownCommand::execute()
{
    controller->movePlayer(Direction::DOWN);
}

// Command *MoveDownCommand::clone()
// {
//     return new MoveDownCommand(*this);
// }