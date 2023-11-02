#include "InputHandler.h"

/**
 * The InputHandler constructor initializes the controller, game, and inputSource objects, and loads
 * commands from a file.
 *
 * @param controller The `controller` parameter is a pointer to an object that implements the `IMove`
 * interface. This object is responsible for handling the movement of the player or character in the
 * game.
 * @param game The "game" parameter is an object of type IGame, which represents the game being played.
 * It is used to interact with the game and perform game-related operations.
 * @param inputSource The input source is an object that provides the input for the game. It could be a
 * keyboard, a mouse, or any other input device.
 */
InputHandler::InputHandler(IMove *controller, IGame *game, InputSource &inputSource) : controller(controller), game(game), inputSource(inputSource)
{
#ifdef LIN
    loadCommandsFromFile("/home/elshad/OOP/game/Input/InputHandler/keys.txt");
#else
    loadCommandsFromFile("C:\\OOP\\Input\\InputHandler\\keys.txt");
#endif
    check();
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
        else if (command == "select")
        {
            keyToCommandMap[key] = new SelectCommand(game);
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
        else if (command == "menu")
        {
            keyToCommandMap[key] = new MenuCommand(game);
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
    std::set<char> usedKeys;
    std::set<std::string> usedCommands;
    std::set<std::string> allCommands = {"MoveUp", "MoveDown", "MoveLeft", "MoveRight", "Start", "Restart", "Select", "SelectLevel", "Quit", "Menu", "Exit"};

    for (auto &pair : keyToCommandMap)
    {
        if (!usedKeys.insert(pair.first).second) // Если ключ уже использовался
        {
            throw std::runtime_error("Key " + std::string(1, pair.first) + " assigned to two commands");
        }

        std::string commandName = typeid(*pair.second).name();
        if (!usedCommands.insert(commandName).second) // Если команда уже была назначена
        {
            throw std::runtime_error("Command " + commandName + " assigned to two keys");
        }
    }

    for (auto &command : allCommands)
    {
        if (usedCommands.find(command) == usedCommands.end()) // Если команда не назначена
        {
            throw std::runtime_error("Command " + command + " is not assigned to any key");
        }
    }
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