#include "LoseMessage.h"

LoseMessage::LoseMessage(PlayerController &controller) : coordinates(controller.getCoordinates()) {}

std::pair<int, int> LoseMessage::getCoordinates() const
{
    return this->coordinates;
}

void LoseMessage::accept(MessageVisitor &v)
{
    v.visit(*this);
}