#ifndef SELECT_LEVEL_COMMAND_H
#define SELECT_LEVEL_COMMAND_H
#include "../Command.h"
#include <functional>

class SelectLevelCommand : public Command {
private:
    std::function<void(int)> selectLevelCallback;
    int level;
public:
    SelectLevelCommand(std::function<void(int)> selectLevelCallback, int level);

    void execute() override;

};

#endif