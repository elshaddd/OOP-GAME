#ifndef OBSERVER_H
#define OBSERVER_H

#include "../Message/Message.h"

class Observer
{
public:
    virtual ~Observer() = default;
    virtual void onEvent(Message &event) = 0;
};

#endif