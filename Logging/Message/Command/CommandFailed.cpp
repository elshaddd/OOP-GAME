#include "CommandFailed.h"

CommandFailed::CommandFailed(char key) {}

char CommandFailed::getKey() const
{
    return key;
}

void CommandFailed::accept(MessageVisitor &v)
{
    v.visit(*this);
}