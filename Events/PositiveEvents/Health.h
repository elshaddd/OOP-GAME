#ifndef POSITIVE_HEALTH_EVENT_H
#define POSITIVE_HEALTH_EVENT_H
#include "../Event.h"
#include "../../PlayerController.h"
#include <utility>

class PositiveHealthEvent : public Event
{
public:
    void OnPlayerStep(PlayerController &controller) override;

    Event *clone() override;
};

#endif