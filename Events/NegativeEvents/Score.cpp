#include "Score.h"
#include "../../Control/PlayerController.h"

void NegativeScoreEvent::OnPlayerStep(PlayerController &controller)
{
    controller.modifyScore(-10);
}

Event *NegativeScoreEvent::clone()
{
    return new NegativeScoreEvent(*this);
}