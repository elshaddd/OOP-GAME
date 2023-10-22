#include "Health.h"
#include "../../PlayerController.h"

void PositiveHealthEvent::OnPlayerStep(PlayerController &controller)
{
    controller.modifyHealth(10);
}

Event *PositiveHealthEvent::clone()
{
    return new PositiveHealthEvent(*this);
}