#ifndef EVENT_H 
#define EVENT_H
#include <utility>

class PlayerController;

class Event
{
public:
    virtual void OnPlayerStep(PlayerController &controller) = 0;
    virtual Event *clone() = 0;
};

#endif