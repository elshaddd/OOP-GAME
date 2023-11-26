#ifndef IGAME_OBSERVER_H
#define IGAME_OBSERVER_H
class Game;
class Display;

class IGameObserver
{
public:
    virtual void update() = 0;

protected:
    virtual Game *getSubject() = 0;

    virtual Display *getDisplay() = 0;
};

#endif