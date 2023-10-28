#include "ConsoleInputSource.h"

char ConsoleInputSource::getInput()
{
    char key;
    std::cin >> key;
    return key;
}
