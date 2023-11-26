#ifndef I_PC_OBSERVER_H
#define I_PC_OBSERVER_H
class PlaPlayerController;
class Display;

class IPCObserver
{
public:
    virtual void update() = 0;

protected:
    virtual PlayerController *getSubject() = 0;

    virtual Display *getDisplay() = 0;
};

#endif