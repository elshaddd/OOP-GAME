#include "StartMessage.h"

StartMessage::StartMessage(GameField &gameField) : fieldParameters(gameField.getWidth(), gameField.getHeight()), startPosition(gameField.getEntrance()) {}

std::pair<int, int> StartMessage::getParameters() const
{
    return this->fieldParameters;
}

std::pair<int, int> StartMessage::getPosition() const
{
    return this->startPosition;
}

void StartMessage::accept(MessageVisitor &v)
{
    v.visit(*this);
}