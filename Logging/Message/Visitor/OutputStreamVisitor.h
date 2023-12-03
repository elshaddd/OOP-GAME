#ifndef OUTPUT_STREAM_VISITOR_H
#define OUTPUT_STREAM_VISITOR_H

#include "MessageVisitor.h"
#include <ostream>
#include <cxxabi.h>
#include <typeinfo>
#include <memory>

class OutputStreamVisitor : public MessageVisitor
{
private:
    std::ostream &os;

public:
    OutputStreamVisitor(std::ostream &os) : os(os) {}
    void visit(CommandExecuted &msg) override;
    void visit(CommandFailed &msg) override;
    void visit(StartMessage &msg) override;
    void visit(WinMessage &msg) override;
    void visit(LoseMessage &msg) override;
};

#endif