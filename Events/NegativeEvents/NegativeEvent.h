#ifndef NEGATIVE_EVENT_H
#define NEGATIVE_EVENT_H
#include "../Event.h"
#include "../../PlayerController.h"
#include <utility>

class NegativeEvent : public Event
{
public:
    virtual void OnPlayerStep(PlayerController &controller) = 0;
};

#endif