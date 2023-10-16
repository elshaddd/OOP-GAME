#include "NegativeEvents.h"
// #include "PlayerController.h"

void NegativeEvent::OnPlayerStep(PlayerController &controller) 
{
    controller.modifyHealth(-10);
}

Event *NegativeEvent::clone()
{
    return new NegativeEvent(*this);
}