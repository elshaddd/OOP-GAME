#include "PositiveEvents.h"

void PositiveEvent::OnPlayerStep(PlayerController &controller)
{
    controller.modifyHealth(10);
}

Event *PositiveEvent::clone()
{
    return new PositiveEvent(*this);
}