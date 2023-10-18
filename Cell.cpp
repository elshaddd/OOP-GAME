#include "Cell.h"

Cell::Cell(bool passable) : passability(passable), event(nullptr) {}

Cell::Cell(const Cell &other) : passability(other.passability), event(other.event ? other.event->clone() : nullptr) {}

Cell::Cell(Cell &&other) noexcept : passability(false), event(nullptr)
{
    std::swap(passability, other.passability);
    std::swap(event, other.event);
}

Cell &Cell::operator=(const Cell &other)
{
    delete event;
    passability = other.passability;
    event = other.event ? other.event->clone() : nullptr;
    return *this;
}

Cell &Cell::operator=(Cell &&other) noexcept
{
    if (this != &other)
    {
        delete event;
        std::swap(passability, other.passability);
        std::swap(event, other.event);
        other.passability = false;
        other.event = nullptr;
    }
    return *this;
}

Cell::~Cell()
{
    delete event;
}

void Cell::setPassability(bool passable)
{
    passability = passable;
}

void Cell::setEvent(Event *newEvent)
{
    if (event)
        delete event;
    event = newEvent;
}

bool Cell::isPassable()
{
    return passability;
}

Event *Cell::getEvent()
{
    return event;
}