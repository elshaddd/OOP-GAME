#include "Restart.h"

RestartCommand::RestartCommand(std::function<void()> restartCallback) : restartCallback(restartCallback) {}

void RestartCommand::execute()
{
    restartCallback();
}