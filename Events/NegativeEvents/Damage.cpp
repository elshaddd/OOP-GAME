#include "Damage.h"
#include "../../PlayerController.h"

void NegativeDamageEvent::OnPlayerStep(PlayerController &controller)
{
    controller.modifyDamage(-10);
}

Event *NegativeDamageEvent::clone()
{
    return new NegativeDamageEvent(*this);
}