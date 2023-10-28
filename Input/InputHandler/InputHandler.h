#ifndef INPUT_READER_H
#define INPUT_READER_H
#include <map>
#include "../Control/PlayerController.h"
#include "../Commands/Command.h"
#include "../Commands/MoveUp/MoveUp.h"
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

    ~InputHandler();
};

#endif