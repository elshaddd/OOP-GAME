#ifndef CELL_H
#define CELL_H
#include <algorithm>
#include "Event.h"

class Cell
{
private:
    bool passability;
    Event *event; // предполагается, что Event - это некий класс события.
public:
    Cell(bool passable = true);

    Cell(const Cell &other);

    Cell(Cell &&other) noexcept;

    Cell &operator=(const Cell &other);

    Cell &operator=(Cell &&other) noexcept;

    ~Cell();

    void setPassability(bool passable);

    bool isPassable();
};

#endif