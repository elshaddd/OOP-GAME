#ifndef NEGATIVE_HEALTH_EVENT_H
#define NEGATIVE_HEALTH_EVENT_H
#include "../Event.h"

class NegativeHealthEvent : public Event
{
public:
    void OnPlayerStep(PlayerController &controller) override;

    Event *clone() override;

    char accept(EventVisitor& visitor) override;
};

#endif