#include "ConsoleInputSource.h"
#include <unistd.h>
#ifdef LIN
#include <termios.h>
#else
#include <conio.h>
#endif

/**
 * The function `getInput()` reads a character from the console input source, either using `getchar()`
 * or `getch()` depending on the platform.
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
    new_tio.c_lflag &= (~ICANON & ~ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_tio);
    key = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &old_tio);

#else
    key = getch();

#endif
    return key;
}
