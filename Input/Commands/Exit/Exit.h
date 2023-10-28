#ifndef EXIT_COMMAND_H
#define EXIT_COMMAND_H
#include "../Command.h"

class ExitCommand : public Command
{
public:
    void execute() override;
    
    // Command *clone() override;
};

#endif