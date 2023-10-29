#include "Start.h"

StartCommand::StartCommand(std::function<void()> startCallback) : startCallback(startCallback) {}

void StartCommand::execute()
{
    startCallback();
}