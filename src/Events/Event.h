#ifndef EVENT_H
#define EVENT_H
#include <utility>
#include "Visitor/EventVisitor.h"

class PlayerController;

class Event
{
public:
    virtual void OnPlayerStep(PlayerController &controller) = 0;
    virtual Event *clone() = 0;
    virtual char accept(EventVisitor& visitor) = 0;
};

#endif