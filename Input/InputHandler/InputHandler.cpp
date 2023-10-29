#include "InputHandler.h"

/**
 * The InputHandler constructor initializes the InputHandler object with the provided parameters and
 * loads commands from a file.
 *
 * @param controller The `PlayerController` object that will handle the player's actions based on the
 * input received.
 * @param inputSource The input source is an object that provides the input for the game. It could be a
 * keyboard, a gamepad, or any other input device. The InputHandler class uses this input source to
 * handle user input and trigger the appropriate actions in the game.
 * @param startCallback A function that will be called when the start button is pressed.
 * @param restartCallback A function that will be called when the user wants to restart the game.
 * @param selectLevelCallback The selectLevelCallback is a function that takes an integer parameter and
 * does some action based on the selected level.
 * @param quitCallback The quitCallback is a function that will be called when the user wants to quit
 * the game.
 */
InputHandler::InputHandler(PlayerController &controller,
                           InputSource &inputSource,
                           std::function<void()> startCallback,
                           std::function<void()> restartCallback,
                           std::function<void(int)> selectLevelCallback,
                           std::function<void()> quitCallback) : controller(controller), inputSource(inputSource), startCallback(startCallback), restartCallback(restartCallback), selectLevelCallback(selectLevelCallback), quitCallback(quitCallback)
{
#ifdef LIN
    loadCommandsFromFile("/home/elshad/OOP/game/Input/InputHandler/keys.txt");
#else
    loadCommandsFromFile("C:\\OOP\\Input\\InputHandler\\keys.txt");
#endif
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
        else if (command == "start")
        {
            keyToCommandMap[key] = new StartCommand(startCallback);
        }
        else if (command == "restart")
        {
            keyToCommandMap[key] = new RestartCommand(restartCallback);
        }
        else if (command.substr(0, 5) == "level")
        {
            int level = std::stoi(command.substr(5));
            keyToCommandMap[key] = new SelectLevelCommand(selectLevelCallback, level);
        }
        else if (command == "quit")
        {
            keyToCommandMap[key] = new QuitCommand(quitCallback);
        }
        else if (command == "exit")
        {
            keyToCommandMap[key] = new ExitCommand();
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

void InputHandler::check()
{
    //
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