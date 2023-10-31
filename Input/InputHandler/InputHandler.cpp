#include "InputHandler.h"

/**
 * The InputHandler constructor initializes the InputHandler object with references to a
 * PlayerController, Game, and InputSource, and loads commands from a file.
 * 
 * @param controller The `PlayerController` object that will handle the player's input and control the
 * game.
 * @param game The "game" parameter is an instance of the Game class. It is used to access and
 * manipulate game-related data and functionality.
 * @param inputSource The input source is an object that provides the input for the game. It could be a
 * keyboard, a mouse, or any other input device. The InputHandler uses this input source to get the
 * user's input and process it accordingly.
 */
InputHandler::InputHandler(PlayerController &controller, Game &game, InputSource &inputSource) : controller(controller), game(game), inputSource(inputSource)
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
            keyToCommandMap[key] = new StartCommand(game);
        }
        else if (command == "restart")
        {
            keyToCommandMap[key] = new RestartCommand(game);
        }
        else if (command.substr(0, 5) == "level")
        {
            int level = std::stoi(command.substr(5));
            keyToCommandMap[key] = new SelectLevelCommand(game, level);
        }
        else if (command == "quit")
        {
            keyToCommandMap[key] = new QuitCommand(game);
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
 * The destructor of the InputHandler class that deletes all the commands stored in the
 * keyToCommandMap.
 */
InputHandler::~InputHandler()
{
    for (auto &pair : keyToCommandMap)
    {
        delete pair.second;
    }
}