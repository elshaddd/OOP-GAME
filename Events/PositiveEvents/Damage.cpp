#include "Damage.h"
#include "../../Control/PlayerController.h"

void PositiveDamageEvent::OnPlayerStep(PlayerController &controller)
{
    controller.modifyDamage(10);
}

Event *PositiveDamageEvent::clone()
{
    return new PositiveDamageEvent(*this);
}

char PositiveDamageEvent::accept(EventVisitor& visitor)
{
    return visitor.visit(*this);
}