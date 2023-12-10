#ifndef CELL_H
#define CELL_H
#include <algorithm>
#include <vector>
#include "../Events/Event.h"

class Cell
{
private:
    bool passability;
    Event *event;

public:
    Cell(bool passable = false);

    Cell(const Cell &other);

    Cell(Cell &&other) noexcept;

    Cell &operator=(const Cell &other);

    Cell &operator=(Cell &&other) noexcept;

    ~Cell();

    void setPassability(bool passable);

    void setEvent(Event *newEvent);

    bool isPassable();

    Event *getEvent();

    void removeEvent();

    friend class FieldGenerator;
};

#endif