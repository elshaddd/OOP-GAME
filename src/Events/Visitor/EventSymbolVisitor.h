#ifndef EVENT_SYMBOL_VISITOR_H
#define EVENT_SYMBOL_VISITOR_H
#include "EventVisitor.h"

class EventSymbolVisitor : public EventVisitor
{
public:
    // char visit(NegativeDamageEvent& event) override;
    char visit(NegativeScoreEvent& event) override;
    char visit(NegativeHealthEvent& event) override;
    // char visit(PositiveDamageEvent& event) override;
    char visit(PositiveScoreEvent& event) override;
    char visit(PositiveHealthEvent& event) override;
    char visit(NeutralCoordsEvent& event) override;
};

#endif