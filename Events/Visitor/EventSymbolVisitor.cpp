#include "EventSymbolVisitor.h"
// #include "../NegativeEvents/Damage.h"
#include "../NegativeEvents/Health.h"
#include "../NegativeEvents/Score.h"
// #include "../PositiveEvents/Damage.h"
#include "../PositiveEvents/Health.h"
#include "../PositiveEvents/Score.h"
#include "../NeutralEvents/Coords.h"

// char EventSymbolVisitor::visit(NegativeDamageEvent &event)
// {
//     return 'd'; // or any other symbol
// }
char EventSymbolVisitor::visit(NegativeScoreEvent &event)
{
    return 'U'; // or any other symbol
}
char EventSymbolVisitor::visit(NegativeHealthEvent &event)
{
    return 'W'; // or any other symbol
}
// char EventSymbolVisitor::visit(PositiveDamageEvent &event)
// {
//     return 'D'; // or any other symbol
// }
char EventSymbolVisitor::visit(PositiveScoreEvent &event)
{
    return 'O'; // or any other symbol
}
char EventSymbolVisitor::visit(PositiveHealthEvent &event)
{
    return '+'; // or any other symbol
}
char EventSymbolVisitor::visit(NeutralCoordsEvent &event)
{
    return '?'; // or any other symbol
}