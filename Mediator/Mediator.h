#ifndef MEDIATOR_H
#define MEDIATOR_H

class Component;

class Mediator{
public :
    virtual void update(Components component) = 0;
};

#endif