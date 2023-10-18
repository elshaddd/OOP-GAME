#include "Score.h"

void PositiveScoreEvent::OnPlayerStep(PlayerController &controller)
{
    controller.modifyScore(10);
}

Event *PositiveScoreEvent::clone()
{
    return new PositiveScoreEvent(*this);
}