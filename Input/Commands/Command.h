#ifndef COMMAND_H
#define COMMAND_H
#include "../../Util/Enums.h"

class Command
{
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
    // virtual Command *clone() = 0;
};

#endif