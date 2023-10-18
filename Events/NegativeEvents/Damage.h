#ifndef NEGATIVE_DAMAGE_EVENT_H
#define NEGATIVE_DAMAGE_EVENT_H
#include "NegativeEvent.h"
// #include "../../PlayerController.h"
// #include <utility>

class NegativeDamageEvent : public NegativeEvent
{
public:
    void OnPlayerStep(PlayerController &controller) override;

    Event *clone() override;
};

#endif