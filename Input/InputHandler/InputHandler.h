#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H
#include <map>
#include <set>
#include <fstream>
#include <typeinfo>
#include <functional>
#include "../../Control/IMove.h"
#include "../../Game/IGame.h"
#include "../Commands/Command.h"
#include "../Commands/MoveUp/MoveUp.h"
#include "../Commands/MoveDown/MoveDown.h"
#include "../Commands/MoveLeft/MoveLeft.h"
#include "../Commands/MoveRight/MoveRight.h"
#include "../Commands/Start/Start.h"
#include "../Commands/Restart/Restart.h"
#include "../Commands/Select/Select.h"
#include "../Commands/SelectLevel/SelectLevel.h"
#include "../Commands/Quit/Quit.h"
#include "../Commands/Menu/Menu.h"
#include "../Commands/Exit/Exit.h"
#include "../InputSource/InputSource.h"

class InputHandler
{
private:
    std::map<char, Command *> keyToCommandMap;
    IMove *controller;
    IGame *game;
    InputSource &inputSource;
    int level;

public:
    InputHandler(IMove *controller, IGame *game, InputSource &inputSource);

    Command *handleInput();

    void loadCommandsFromFile(const std::string &filename);

    void check();

    ~InputHandler();
};

#endif