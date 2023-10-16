#ifndef POSITIVE_EVENT_H 
#define POSITIVE_EVENT_H
#include "Event.h"
#include "PlayerController.h"
#include <utility>


class PositiveEvent : public Event
{
public:
    void OnPlayerStep(PlayerController &controller) override;

    Event *clone() override;
};

#endif