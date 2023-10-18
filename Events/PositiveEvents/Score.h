#ifndef POSITIVE_SCORE_EVENT_H
#define POSITIVE_SCORE_EVENT_H
#include "../Event.h"
#include "../../PlayerController.h"
#include <utility>

class PositiveScoreEvent : public Event
{
public:
    void OnPlayerStep(PlayerController &controller) override;

    Event *clone() override;
};

#endif