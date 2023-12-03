#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "../Message/Message.h"
#include "../Logger/Observer.h"
#include <vector>
#include <memory>

class MessageDispatcher
{
private:
    std::vector<Observer *> observers;

public:
    void addObserver(Observer *observer);

    void dispatchEvent(Message &event);

    ~MessageDispatcher();
};

#endif