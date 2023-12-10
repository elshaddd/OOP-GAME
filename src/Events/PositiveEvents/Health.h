#ifndef POSITIVE_HEALTH_EVENT_H
#define POSITIVE_HEALTH_EVENT_H
#include "../Event.h"

class PositiveHealthEvent : public Event
{
public:
    void OnPlayerStep(PlayerController &controller) override;

    Event *clone() override;

    char accept(EventVisitor& visitor) override;
};

#endif