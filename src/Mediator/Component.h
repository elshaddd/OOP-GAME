#ifndef COMPONENT_H
#define COMPONENT_H
#include "../Util/Enums.h"

class Mediator;

class Component{
public :
    virtual void setMediator(Mediator *mediator) = 0;
    virtual void notify() = 0;
};

#endif