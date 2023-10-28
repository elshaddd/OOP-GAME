#include "ConsoleInputSource.h"

char ConsoleInputSource::getInput()
{
    char key;
    // std::cin >> key;
    key = getch();
    return key;
}
