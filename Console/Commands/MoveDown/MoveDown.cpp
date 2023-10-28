#include "MoveDown.h"
#include "../../../Control/PlayerController.h"

MoveDownCommand::MoveDownCommand(PlayerController &controller) : controller(controller) {}

void MoveDownCommand::execute()
{
    controller.movePlayer(Direction::DOWN);
}