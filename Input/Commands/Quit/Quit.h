#ifndef QUIT_COMMAND_H
#define QUIT_COMMAND_H
#include "../Command.h"
#include <functional>

class QuitCommand : public Command
{
private:
    std::function<void()> quitCallback;

public:
    QuitCommand(std::function<void()> quitCallback);

    void execute() override;
};

#endif