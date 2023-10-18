#ifndef CELL_H
#define CELL_H
#include <algorithm>
#include <vector>
#include "Event.h"

class Cell
{
private:
    bool passability;
    Event *event; 
    std::vector<Cell *> neighbours;
public:
    Cell(bool passable = false);

    Cell(const Cell &other);

    Cell(Cell &&other) noexcept;

    Cell &operator=(const Cell &other);

    Cell &operator=(Cell &&other) noexcept;

    ~Cell();

    void setPassability(bool passable);

    bool isPassable();

    void addNeighbour(Cell *neighbour);

    friend class FieldGenerator;
};
#endif