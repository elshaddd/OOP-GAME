#ifndef INVOKER_H
#define INVOKER_H
#include "../Input/Commands/Command.h"
#include "../Logging/Dispatcher/MessageDispatcher.h"
#include "../Logging/Message/Command/CommandExecuted.h"
#include "../Logging/Message/Command/CommandFailed.h"

class Invoker
{
    MessageDispatcher *dispatcher;

public:
    Invoker(MessageDispatcher *dispatcher);
    void call(std::pair<char, Command *> pair);
};

#endif