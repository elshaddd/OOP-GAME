#include "Health.h"

void NegativeHealthEvent::OnPlayerStep(PlayerController &controller)
{
    controller.modifyHealth(-10);
}

Event *NegativeHealthEvent::clone()
{
    return new NegativeHealthEvent(*this);
}