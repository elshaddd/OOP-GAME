#include "CommandExecuted.h"

CommandExecuted::CommandExecuted(char key, Command *command) {}

char CommandExecuted::getKey() const
{
    return key;
}

Command *CommandExecuted::getCommand() const
{
    return command;
}

void CommandExecuted::accept(MessageVisitor &v)
{
    v.visit(*this);
}