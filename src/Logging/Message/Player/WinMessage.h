#ifndef WIN_MESSAGE_H
#define WIN_MESSAGE_H

#include "../Message.h"
#include "../../../Player/Player.h"
#include "../Visitor/MessageVisitor.h"
#include <ostream>

struct PlayerStats
{
    int health;
    int score;
};

class WinMessage : public Message
{
private:
    PlayerStats stats;

public:
    WinMessage(Player &player);
    PlayerStats getStats() const;
    void accept(MessageVisitor &v) override;
};

#endif