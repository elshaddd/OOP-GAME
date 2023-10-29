#include "InputHandler.h"

/**
 * The InputHandler constructor initializes the controller and inputSource objects and loads commands
 * from a file.
 *
 * @param controller The `PlayerController` object that will be used to handle player input and control
 * the game.
 * @param inputSource The input source is an object that provides the input for the game. It could be a
 * keyboard, a mouse, or any other input device. The InputHandler class uses this input source to get
 * the user's input.
 */
InputHandler::InputHandler(PlayerController &controller, InputSource &inputSource) : controller(controller), inputSource(inputSource)
{
    loadCommandsFromFile("C:\\OOP\\Input\\InputHandler\\keys.txt");
}

/**
 * The function "loadCommandsFromFile" reads commands from a file and maps them to specific keys.
 *
 * @param filename The `filename` parameter is a string that represents the name of the file from which
 * the commands will be loaded.
 */
void InputHandler::loadCommandsFromFile(const std::string &filename)
{
    std::ifstream file(filename);
    char key;
    std::string command;
    while (file >> key >> command)
    {
        if (command == "up")
        {
            keyToCommandMap[key] = new MoveUpCommand(controller);
        }
        else if (command == "down")
        {
            keyToCommandMap[key] = new MoveDownCommand(controller);
        }
        else if (command == "left")
        {
            keyToCommandMap[key] = new MoveLeftCommand(controller);
        }
        else if (command == "right")
        {
            keyToCommandMap[key] = new MoveRightCommand(controller);
        }
        else if (command == "exit")
        {
            keyToCommandMap[key] = new ExitCommand();
        }
        else if (command == "quit")
        {
            IGame *game;
            keyToCommandMap[key] = new QuitCommand(*game);
        }
    }
}

/**
 * The handleInput function checks if a key is mapped to a command and returns the corresponding
 * command if found.
 *
 * @return a pointer to a Command object.
 */
Command *InputHandler::handleInput()
{
    char key = inputSource.getInput();
    if (keyToCommandMap.find(key) != keyToCommandMap.end())
    {
        return keyToCommandMap[key];
    }
    return nullptr;
}

/**
 * The destructor of the InputHandler class deletes all the commands stored in the keyToCommandMap.
 */
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