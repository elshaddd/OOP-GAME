#ifndef MESSAGE_VISITOR_H
#define MESSAGE_VISITOR_H
class CommandExecuted;
class CommandFailed;
class StartMessage;
class WinMessage;
class LoseMessage;

class MessageVisitor
{
public:
    virtual void visit(CommandExecuted &elem) = 0;
    virtual void visit(CommandFailed &elem) = 0;
    virtual void visit(StartMessage &elem) = 0;
    virtual void visit(WinMessage &elem) = 0;
    virtual void visit(LoseMessage &elem) = 0;
};

#endif