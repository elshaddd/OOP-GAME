#ifndef NEGATIVE_DAMAGE_EVENT_H
#define NEGATIVE_DAMAGE_EVENT_H
#include "../Event.h"

class NegativeDamageEvent : public Event
{
public:
    void OnPlayerStep(PlayerController &controller) override;

    Event *clone() override;
};

#endif