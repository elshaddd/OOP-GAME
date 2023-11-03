#ifndef IGAME_H
#define IGAME_H

class IGame
{
public:
    virtual void start() = 0;

    virtual void restart() = 0;

    virtual void select() = 0;

    virtual void selectLevel(int level) = 0;

    virtual void quit() = 0;

    virtual void menu() = 0;

    virtual void exit() = 0;
};

#endif