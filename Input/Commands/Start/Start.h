#ifndef START_COMMAND_H
#define START_COMMAND_H
#include "../Command.h"
#include <functional>

class StartCommand : public Command
{
private:
    std::function<void()> startCallback;

public:
    StartCommand(std::function<void()> startCallback);

    void execute() override;
};

#endif