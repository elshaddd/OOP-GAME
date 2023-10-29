#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H
#include <map>
#include <fstream>
#include "../../Control/PlayerController.h"
#include "../Commands/Command.h"
#include "../Commands/MoveUp/MoveUp.h"
#include "../Commands/MoveDown/MoveDown.h"
#include "../Commands/MoveLeft/MoveLeft.h"
#include "../Commands/MoveRight/MoveRight.h"
#include "../Commands/Exit/Exit.h"
#include "../Commands/Quit/Quit.h"
#include "../InputSource/InputSource.h"

class InputHandler
{
private:
    std::map<char, Command *> keyToCommandMap;
    PlayerController &controller;
    InputSource &inputSource;

public:
    InputHandler(PlayerController &controller, InputSource &inputSource);

    Command *handleInput();

    void loadCommandsFromFile(const std::string& filename);

    ~InputHandler();

    // InputHandler(const InputHandler &other);
    
    // InputHandler &operator=(const InputHandler &other);
};

#endif