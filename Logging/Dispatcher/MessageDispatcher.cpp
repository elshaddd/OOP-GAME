#include "MessageDispatcher.h"

void MessageDispatcher::addObserver(std::shared_ptr<Observer> observer)
{
    observers.push_back(observer);
}

void MessageDispatcher::dispatchEvent(Message &event)
{
    for (auto &observer : observers)
    {
        observer->onEvent(event);
    }
}