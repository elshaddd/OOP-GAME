#ifndef COMMAND_H
#define COMMAND_H
#include "../../Util/Enums.h"

class PlayerController;

class Command {
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
};

#endif