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
//     return 'd';
// }
char EventSymbolVisitor::visit(NegativeScoreEvent &event)
{
    return 'U';
}
char EventSymbolVisitor::visit(NegativeHealthEvent &event)
{
    return 'W';
}
// char EventSymbolVisitor::visit(PositiveDamageEvent &event)
// {
//     return 'D';
// }
char EventSymbolVisitor::visit(PositiveScoreEvent &event)
{
    return 'O';
}
char EventSymbolVisitor::visit(PositiveHealthEvent &event)
{
    return '+';
}
char EventSymbolVisitor::visit(NeutralCoordsEvent &event)
{
    return '?';
}