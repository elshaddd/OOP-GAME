#ifndef NEUTRAL_COORDS_EVENT_H
#define NEUTRAL_COORDS_EVENT_H
#include "../Event.h"

class NeutralCoordsEvent : public Event
{
private:
    std::pair<int, int> newCoordinates;

public:
    NeutralCoordsEvent(std::pair<int, int> coords);

    void OnPlayerStep(PlayerController &controller) override;

    Event *clone() override;

    char accept(EventVisitor& visitor) override;
};

#endif