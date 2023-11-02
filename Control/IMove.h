#ifndef IMOVE_H
#define IMOVE_H
#include "../Util/Enums.h"

class IMove
{
public:
    virtual void movePlayer(Direction direction) = 0;
};

#endif