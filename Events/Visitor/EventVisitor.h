#ifndef EVENT_VISITOR_H
#define EVENT_VISITOR_H
class NegativeDamageEvent;
class NegativeHealthEvent;
class NegativeScoreEvent;
class PositiveDamageEvent;
class PositiveHealthEvent;
class PositiveScoreEvent;
class NeutralCoordsEvent;

class EventVisitor
{
public:
    virtual char visit(NegativeDamageEvent& event) = 0;
    virtual char visit(NegativeHealthEvent& event) = 0;
    virtual char visit(NegativeScoreEvent& event) = 0;
    virtual char visit(PositiveDamageEvent& event) = 0;
    virtual char visit(PositiveHealthEvent& event) = 0;
    virtual char visit(PositiveScoreEvent& event) = 0;
    virtual char visit(NeutralCoordsEvent& event) = 0;
};

#endif