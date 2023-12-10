#ifndef START_MESSAGE_H
#define START_MESSAGE_H

#include "../Message.h"
#include "../../../Field/Field.h"
#include "../Visitor/MessageVisitor.h"
#include <ostream>

class StartMessage : public Message
{
private:
    std::pair<int, int> fieldParameters;
    std::pair<int, int> startPosition;

public:
    StartMessage(GameField &gameField);
    std::pair<int, int> getParameters() const;
    std::pair<int, int> getPosition() const;
    void accept(MessageVisitor &v) override;
};

#endif