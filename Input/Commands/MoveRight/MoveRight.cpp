#include "MoveRight.h"
#include "../../../Control/PlayerController.h"

MoveRightCommand::MoveRightCommand(PlayerController &controller) : controller(controller) {}

void MoveRightCommand::execute()
{
    controller.movePlayer(Direction::RIGHT);
}