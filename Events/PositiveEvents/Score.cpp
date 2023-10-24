#include "Score.h"
#include "../../Control/PlayerController.h"

void PositiveScoreEvent::OnPlayerStep(PlayerController &controller)
{
    controller.modifyScore(10);
}

Event *PositiveScoreEvent::clone()
{
    return new PositiveScoreEvent(*this);
}

char PositiveScoreEvent::accept(EventVisitor& visitor)
{
    return visitor.visit(*this);
}