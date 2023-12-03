#include "MessageDispatcher.h"

void MessageDispatcher::addObserver(Observer *observer)
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

MessageDispatcher::~MessageDispatcher()
{
    for (auto &observer : observers)
    {
        delete observer;
    }
}