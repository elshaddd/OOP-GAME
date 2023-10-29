#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H
#include <map>
#include <fstream>
#include <functional>
#include "../../Control/PlayerController.h"
#include "../Commands/Command.h"
#include "../Commands/MoveUp/MoveUp.h"
#include "../Commands/MoveDown/MoveDown.h"
#include "../Commands/MoveLeft/MoveLeft.h"
#include "../Commands/MoveRight/MoveRight.h"
#include "../Commands/Start/Start.h"
#include "../Commands/Restart/Restart.h"
#include "../Commands/SelectLevel/SelectLevel.h"
#include "../Commands/Quit/Quit.h"
#include "../Commands/Exit/Exit.h"
#include "../InputSource/InputSource.h"

class InputHandler
{
private:
    std::map<char, Command *> keyToCommandMap;
    PlayerController &controller;
    InputSource &inputSource;
    std::function<void()> quitCallback;
    std::function<void(int)> selectLevelCallback;
    std::function<void()> startCallback;
    std::function<void()> restartCallback;
    int level;

public:
    InputHandler(PlayerController &controller, InputSource &inputSource, std::function<void()> startCallback, std::function<void()> restartCallback, std::function<void(int)> selectLevelCallback, std::function<void()> quitCallback);

    Command *handleInput();

    void loadCommandsFromFile(const std::string &filename);

    void check();

    ~InputHandler();

    // InputHandler(const InputHandler &other);

    // InputHandler &operator=(const InputHandler &other);
};

#endif