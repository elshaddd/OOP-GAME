#include "Exit.h"
#include "../../../Control/PlayerController.h"

void ExitCommand::execute()
{
    exit(0);
}

// Command *ExitCommand::clone()
// {
//     return new ExitCommand(*this);
// }