#include "MoveLeft.h"
#include "../../../Control/PlayerController.h"

MoveLeftCommand::MoveLeftCommand(PlayerController &controller) : controller(controller) {}

void MoveLeftCommand::execute()
{
    controller.movePlayer(Direction::LEFT);
}