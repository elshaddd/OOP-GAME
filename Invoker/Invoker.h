#ifndef INVOKER_H
#define INVOKER_H
#include "../Input/InputHandler/InputHandler.h"

class Invoker
{
private:
    Command *command;

public:
    Invoker(Command *c);
    void call();
};

#endif