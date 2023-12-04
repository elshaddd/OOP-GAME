#ifndef COMMAND_H
#define COMMAND_H
#include "../../Util/Enums.h"
#include <vector>

class Command
{
public:
    virtual ~Command() = default;
    virtual void execute() = 0;
    virtual std::vector<Status> getValidation() = 0;
    // virtual Command *clone() = 0;
};

#endif