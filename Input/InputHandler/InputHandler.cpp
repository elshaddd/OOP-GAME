#include "InputHandler.h"

InputHandler::InputHandler(PlayerController &controller, InputSource &inputSource) : controller(controller), inputSource(inputSource)
{
    keyToCommandMap['w'] = new MoveUpCommand(controller);
    keyToCommandMap['s'] = new MoveDownCommand(controller);
    keyToCommandMap['a'] = new MoveLeftCommand(controller);
    keyToCommandMap['d'] = new MoveRightCommand(controller);
    keyToCommandMap['`'] = new ExitCommand();
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

// InputHandler::InputHandler(const InputHandler &other) : controller(other.controller), inputSource(other.inputSource)
// {
//     for (const auto &pair : other.keyToCommandMap)
//     {
//         keyToCommandMap[pair.first] = pair.second->clone();
//     }
// }

// InputHandler &InputHandler::operator=(const InputHandler &other)
// {
//     if (this != &other)
//     {
//         for (auto &pair : keyToCommandMap)
//         {
//             delete pair.second;
//         }
//         controller = other.controller;
//         inputSource = other.inputSource;
//         for (const auto &pair : other.keyToCommandMap)
//         {
//             keyToCommandMap[pair.first] = pair.second->clone();
//         }
//     }
//     // if (this != &other)
//     // {
//     //     controller = other.controller;
//     //     inputSource = other.inputSource;

//     //     for (auto &pair : keyToCommandMap)
//     //     {
//     //         delete pair.second;
//     //     }
//     //     keyToCommandMap.clear();

//     //     for (const auto &pair : other.keyToCommandMap)
//     //     {
//     //         keyToCommandMap[pair.first] = pair.second->clone();
//     //     }
//     // }
//     return *this;
// }