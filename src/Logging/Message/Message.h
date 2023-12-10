#ifndef MESSAGE_H
#define MESSAGE_H
#include <iostream>
#include "Visitor/OutputStreamVisitor.h"

class Message
{
public:
    virtual ~Message() = default;
    virtual void accept(MessageVisitor &v) = 0;
};

std::ostream &operator<<(std::ostream &os, Message &msg);

#endif