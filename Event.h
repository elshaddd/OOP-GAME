#ifndef EVENT_H
#define EVENT_H
#include "PlayerController.h"
class PlayerController;

class Event
{
public:
    // virtual void OnPlayerStep(Player &player) = 0;
    virtual void OnPlayerStep(PlayerController &controller) = 0;
    virtual Event *clone() = 0;
};

class PositiveEvent : public Event
{
public:
    void OnPlayerStep(PlayerController &controller) override
    {
        controller.modifyHealth(10);
    }

    Event *clone() override
    {
        return new PositiveEvent(*this);
    }
};

class NegativeEvent : public Event
{
public:
    void OnPlayerStep(PlayerController &controller) override
    {
        controller.modifyHealth(-10);
    }

    Event *clone() override
    {
        return new NegativeEvent(*this);
    }
};

class CoordinateChangeEvent : public Event
{
private:
    std::pair<int, int> newCoordinates;

public:
    CoordinateChangeEvent(std::pair<int, int> coords) : newCoordinates(coords) {}

    void OnPlayerStep(PlayerController &controller) override
    {
        controller.setCoordinates(newCoordinates);
    }
    Event *clone() override
    {
        return new CoordinateChangeEvent(*this);
    }
};

#endif