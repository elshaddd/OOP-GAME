#ifndef MENU_COMMAND_H
#define MENU_COMMAND_H
#include "../Command.h"
#include <functional>
#include "../../../Game/IGame.h"

class MenuCommand : public Command
{
private:
    IGame *game;

public:
    MenuCommand(IGame *game);

    void execute() override;

    std::vector<Status> getValidation() override;
};

#endif