#ifndef INVOKER_H
#define INVOKER_H
#include "../Input/Commands/Command.h"

class Invoker
{
public:
    void call(Command *command);
};

#endif