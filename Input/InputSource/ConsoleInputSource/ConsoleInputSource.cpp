#include "ConsoleInputSource.h"

/**
 * The function `getInput()` reads a character input from the console using the `getch()` function.
 * 
 * @return a character, which is the input received from the console.
 */
char ConsoleInputSource::getInput()
{
    char key;
    // std::cin >> key;
    key = getch();
    return key;
}
