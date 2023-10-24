#ifndef POSITIVE_DAMAGE_EVENT_H
#define POSITIVE_DAMAGE_EVENT_H
#include "../Event.h"

class PositiveDamageEvent : public Event
{
public:
    void OnPlayerStep(PlayerController &controller) override;

    Event *clone() override;

    char accept(EventVisitor& visitor) override;
};

#endif