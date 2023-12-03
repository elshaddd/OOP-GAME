#include "Message.h"

std::ostream &operator<<(std::ostream &os, Message &msg)
{
    OutputStreamVisitor v(os);
    msg.accept(v);
    return os;
}