#ifndef POSITIVE_SCORE_EVENT_H
#define POSITIVE_SCORE_EVENT_H
#include "../Event.h"

class PositiveScoreEvent : public Event
{
public:
    void OnPlayerStep(PlayerController &controller) override;

    Event *clone() override;

    char accept(EventVisitor& visitor) override;
};

#endif