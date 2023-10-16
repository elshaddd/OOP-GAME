#include "NeutralEvents.h"
// #include "PlayerController.h"


CoordinateChangeEvent::CoordinateChangeEvent(std::pair<int, int> coords) : newCoordinates(coords) {}

void CoordinateChangeEvent::OnPlayerStep(PlayerController &controller)
{
    controller.setCoordinates(newCoordinates);
}

Event *CoordinateChangeEvent::clone()
{
    return new CoordinateChangeEvent(*this);
}