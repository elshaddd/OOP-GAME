#include "MoveUp.h"
#include "../../../Control/PlayerController.h"

MoveUpCommand::MoveUpCommand(PlayerController &controller) : controller(controller) {}

void MoveUpCommand::execute()
{
    controller.movePlayer(Direction::UP);
}