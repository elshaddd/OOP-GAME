#ifndef COMMAND_FAILED_MESSAGE_H
#define COMMAND_FAILED_MESSAGE_H

#include "../Message.h"
#include "../../../Input/Commands/Command.h"
#include "../Visitor/MessageVisitor.h"
#include <ostream>

class CommandFailed : public Message
{
private:
    char key;

public:
    CommandFailed(char key);
    char getKey() const;
    void accept(MessageVisitor &v) override;
};

#endif