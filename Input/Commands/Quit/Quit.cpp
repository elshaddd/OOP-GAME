#include "Quit.h"

QuitCommand::QuitCommand(std::function<void()> quitCallback) : quitCallback(quitCallback) {}

void QuitCommand::execute()
{
    quitCallback();
}