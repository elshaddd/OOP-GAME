#ifndef COMMAND_EXECUTED_MESSAGE_H
#define COMMAND_EXECUTED_MESSAGE_H

#include "../Message.h"
#include "../../../Input/Commands/Command.h"
#include "../Visitor/MessageVisitor.h"

class CommandExecuted : public Message
{
private:
    char key;
    Command *command;

public:
    CommandExecuted(char key, Command *command);
    char getKey() const;
    Command *getCommand() const;
    void accept(MessageVisitor &v) override;
};

#endif