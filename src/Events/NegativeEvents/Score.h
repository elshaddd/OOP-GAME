#ifndef NEGATIVE_SCORE_EVENT_H
#define NEGATIVE_SCORE_EVENT_H
#include "../Event.h"

class NegativeScoreEvent : public Event
{
public:
    void OnPlayerStep(PlayerController &controller) override;

    Event *clone() override;

    char accept(EventVisitor& visitor) override;
};

#endif