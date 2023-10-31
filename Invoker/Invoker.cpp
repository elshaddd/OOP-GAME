#include "Invoker.h"

Invoker::Invoker(Command *c) : command(c) {}

void Invoker::call()
{
    if (command)
        command->execute();
}
