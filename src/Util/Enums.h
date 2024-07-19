#ifndef ENUMS_H
#define ENUMS_H

enum Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

enum Characteristics
{
    HEALTH,
    SCORE,
    DAMAGE
};

enum Status
{
    MENU,
    SELECTING,
    PAUSE,
    RUN,
    OVER,
    WIN,
    EXIT,
    PASS
};

enum Components
{
    GAME,
    MOVEMENT
};

#endif