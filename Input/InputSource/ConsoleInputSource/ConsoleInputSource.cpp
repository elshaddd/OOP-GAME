#include "ConsoleInputSource.h"
#include <unistd.h>
#ifndef LIN
#include <conio.h>
#else
#include <termios.h>
#endif

/**
 * The function `getInput()` reads a character input from the console using the `getch()` function.
 * 
 * @return a character, which is the input received from the console.
 */
char ConsoleInputSource::getInput()
{
    char key;

    #ifdef LIN
    struct termios old_tio, new_tio;
    tcgetattr(STDIN_FILENO, &old_tio);
    new_tio = old_tio;
    new_tio.c_lflag &=(~ICANON & ~ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);
    key = getchar();

    #else
    key = getch();

    #endif
    return key;
}
