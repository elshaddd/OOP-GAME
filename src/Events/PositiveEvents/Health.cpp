#include "Health.h"
#include "../../Control/PlayerController.h"

void PositiveHealthEvent::OnPlayerStep(PlayerController &controller)
{
    controller.modifyHealth(10);
}

Event *PositiveHealthEvent::clone()
{
    return new PositiveHealthEvent(*this);
}

char PositiveHealthEvent::accept(EventVisitor& visitor)
{
    return visitor.visit(*this);
}