#include "Damage.h"

void PositiveDamageEvent::OnPlayerStep(PlayerController &controller)
{
    controller.modifyDamage(10);
}

Event *PositiveDamageEvent::clone()
{
    return new PositiveDamageEvent(*this);
}