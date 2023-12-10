#ifndef EXIT_COMMAND_H
#define EXIT_COMMAND_H
#include "../Command.h"
#include "../../../Game/IGame.h"


class ExitCommand : public Command
{
private:
    IGame *game;

public:
    ExitCommand(IGame *game);

    void execute() override;

    std::vector<Status> getValidation() override;
};

#endif