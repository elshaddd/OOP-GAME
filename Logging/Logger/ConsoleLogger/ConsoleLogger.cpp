#include "ConsoleLogger.h"

void ConsoleLogger::onEvent(Message &event)
{
    std::cout << event << '\n';
}