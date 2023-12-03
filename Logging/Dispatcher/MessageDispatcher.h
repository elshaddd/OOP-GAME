#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "../Message/Message.h"
#include "../Logger/Observer.h"
#include <vector>
#include <memory>

class MessageDispatcher
{
private:
    std::vector<std::shared_ptr<Observer>> observers;

public:
    void addObserver(std::shared_ptr<Observer> observer);

    void dispatchEvent(Message &event);
};

#endif