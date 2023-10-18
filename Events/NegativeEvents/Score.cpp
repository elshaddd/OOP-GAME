#include "Score.h"

void NegativeScoreEvent::OnPlayerStep(PlayerController &controller)
{
    controller.modifyScore(-10);
}

Event *NegativeScoreEvent::clone()
{
    return new NegativeScoreEvent(*this);
}