#ifndef NEGATIVE_SCORE_EVENT_H
#define NEGATIVE_SCORE_EVENT_H
// #include "../Event.h"
// #include "../../PlayerController.h"
// #include <utility>
#include "NegativeEvent.h"

class NegativeScoreEvent : public NegativeEvent
{
public:
    void OnPlayerStep(PlayerController &controller) override;

    Event *clone() override;
};

#endif