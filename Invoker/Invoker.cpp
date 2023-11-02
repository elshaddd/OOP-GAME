#include "Invoker.h"

void Invoker::call(Command *command)
{
    if (command)
        command->execute();
}
