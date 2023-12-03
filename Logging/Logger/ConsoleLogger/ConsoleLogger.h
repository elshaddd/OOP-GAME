#ifndef CONSOLE_LOGGER_H
#define CONSOLE_LOGGER_H

#include "../Observer.h"
#include <string>
#include <iostream>

class ConsoleLogger : public Observer
{
public:
    void onEvent(Message &event) override;
};

#endif