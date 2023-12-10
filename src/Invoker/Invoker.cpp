#include "Invoker.h"

Invoker::Invoker(MessageDispatcher *dispatcher) : dispatcher(dispatcher) {}

void Invoker::call(std::pair<char, Command *> pair)
{
    if (pair.second)
    {
        pair.second->execute();
        if (dispatcher != nullptr)
        {
            CommandExecuted event(pair.first, pair.second);
            dispatcher->dispatchEvent(event);
        }
    }
    else
    {
        if (dispatcher != nullptr)
        {
            CommandFailed event(pair.first);
            dispatcher->dispatchEvent(event);
        }
    }
}