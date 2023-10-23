#include "Coords.h"
#include "../../Control/PlayerController.h"

NeutralCoordsEvent::NeutralCoordsEvent(std::pair<int, int> coords) : newCoordinates(coords) {}

void NeutralCoordsEvent::OnPlayerStep(PlayerController &controller)
{
    controller.setCoordinates(newCoordinates);
}

Event *NeutralCoordsEvent::clone()
{
    return new NeutralCoordsEvent(*this);
}