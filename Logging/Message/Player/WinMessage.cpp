#include "WinMessage.h"

WinMessage::WinMessage(Player &player)
{
    this->stats.health = player.getHealth();
    this->stats.score = player.getScore();
}

PlayerStats WinMessage::getStats() const
{
    return stats;
}

void WinMessage::accept(MessageVisitor &v)
{
    v.visit(*this);
}