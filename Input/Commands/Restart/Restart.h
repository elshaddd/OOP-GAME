#ifndef RESTART_COMMAND_H
#define RESTART_COMMAND_H
#include "../Command.h"
#include <functional>

class RestartCommand : public Command {
private:
    std::function<void()> restartCallback;
public:
    RestartCommand(std::function<void()> restartCallback);

    void execute() override;

};

#endif