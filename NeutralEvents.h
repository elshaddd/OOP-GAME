#ifndef NEUTRAL_EVENT_H 
#define NEUTRAL_EVENT_H
#include "Event.h"
#include "PlayerController.h"
#include <utility>

class CoordinateChangeEvent : public Event
{
private:
    std::pair<int, int> newCoordinates;

public:
    CoordinateChangeEvent(std::pair<int, int> coords);

    void OnPlayerStep(PlayerController &controller) override;
    Event *clone() override;
};

#endif