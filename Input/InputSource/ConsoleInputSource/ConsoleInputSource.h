#ifndef CONSOLE_INPUT_SOURCE_H
#define CONSOLE_INPUT_SOURCE_H
#include "../InputSource.h"
#include <iostream>
#include <conio.h>

class ConsoleInputSource : public InputSource
{
public:
    char getInput() override;
};

#endif