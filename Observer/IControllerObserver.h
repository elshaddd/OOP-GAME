#ifndef I_CONTROLLER_OBSERVER_H
#define I_CONTROLLER_OBSERVER_H

class IControllerObserver
{
public:
    virtual void update() = 0;

    // protected:
    //     virtual PlayerController *getSubject() = 0;

    //     virtual Display *getDisplay() = 0;
};

#endif