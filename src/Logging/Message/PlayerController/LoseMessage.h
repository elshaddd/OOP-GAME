#ifndef LOSE_MESSAGE_H
#define LOSE_MESSAGE_H
#include "../Message.h"
#include "../../../Control/PlayerController.h"
#include "../Visitor/MessageVisitor.h"
#include <ostream>

class LoseMessage : public Message
{
private:
    std::pair<int, int> coordinates;

public:
    LoseMessage(PlayerController &controller);
    std::pair<int, int> getCoordinates() const;
    void accept(MessageVisitor &v) override;
};

#endif