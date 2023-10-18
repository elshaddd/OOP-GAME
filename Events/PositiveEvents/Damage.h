#ifndef POSITIVE_DAMAGE_EVENT_H
#define POSITIVE_DAMAGE_EVENT_H
#include "../Event.h"
#include "../../PlayerController.h"
#include <utility>

class PositiveDamageEvent : public Event
{
public:
    void OnPlayerStep(PlayerController &controller) override;

    Event *clone() override;
};

#endif