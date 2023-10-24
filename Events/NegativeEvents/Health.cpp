#include "Health.h"
#include "../../Control/PlayerController.h"

void NegativeHealthEvent::OnPlayerStep(PlayerController &controller)
{
    controller.modifyHealth(-10);
}

Event *NegativeHealthEvent::clone()
{
    return new NegativeHealthEvent(*this);
}

char NegativeHealthEvent::accept(EventVisitor& visitor)
{
    return visitor.visit(*this);
}