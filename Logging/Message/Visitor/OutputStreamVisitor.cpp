#include "OutputStreamVisitor.h"
#include "../Command/CommandExecuted.h"
#include "../Command/CommandFailed.h"
#include "../Game/StartMessage.h"
#include "../Player/WinMessage.h"
#include "../PlayerController/LoseMessage.h"

void OutputStreamVisitor::visit(CommandExecuted &msg)
{
    int status;
    std::unique_ptr<char, void (*)(void *)> res{
        abi::__cxa_demangle(typeid(*msg.getCommand()).name(), NULL, NULL, &status),
        std::free};
    os << "Command executed. Input: " << msg.getKey() << ", Command: " << (status == 0 ? res.get() : "Command");
}

void OutputStreamVisitor::visit(CommandFailed &msg)
{
    os << "Command failed. Input: " << msg.getKey();
}

void OutputStreamVisitor::visit(StartMessage &msg)
{
    os << "New game started. Field size " << msg.getParameters().first << ':' << msg.getParameters().second
       << ". Player start position: (" << msg.getPosition().first << ", " << msg.getPosition().second << ')';
}

void OutputStreamVisitor::visit(WinMessage &msg)
{
    os << "Player won. Player health: " << msg.getStats().health << ". Player score: " << msg.getStats().score;
}

void OutputStreamVisitor::visit(LoseMessage &msg)
{
    os << "Player lost. Event happened at coordinates: (" << msg.getCoordinates().first << ", " << msg.getCoordinates().second << ')';
}