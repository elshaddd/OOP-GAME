#include "InputHandler.h"

InputHandler::InputHandler(PlayerController &controller, InputSource &inputSource) : controller(controller), inputSource(inputSource)
{
    keyToCommandMap['w'] = new MoveUpCommand(controller);
    // need to add
}

Command *InputHandler::handleInput()
{
    char key = inputSource.getInput();
    if (keyToCommandMap.find(key) != keyToCommandMap.end())
    {
        return keyToCommandMap[key];
    }
    return nullptr;
}

InputHandler::~InputHandler()
{
    for (auto &pair : keyToCommandMap)
    {
        delete pair.second;
    }
}