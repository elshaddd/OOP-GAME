#ifndef CONSOLE_INPUT_SOURCE_H
#define CONSOLE_INPUT_SOURCE_H
#include "../InputSource.h"
#include <iostream>

class ConsoleInputSource : public InputSource
{
public:
    char getInput() override;
};

#endif