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
}

/**
 * The function "loadCommandsFromFile" reads commands from a file and maps them to specific keys.
 *
 * @param filename The `filename` parameter is a string that represents the name of the file from which
 * the commands will be loaded.
 */
void InputHandler::loadCommandsFromFile(const std::string &filename)
{
    checkFile(filename);
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
            keyToCommandMap[key] = new ExitCommand(game);
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
 * The function `checkFile` reads a file containing key-command mappings and checks for any errors or
 * missing mappings.
 *
 * @param filename The `filename` parameter is a string that represents the name of the file to be
 * checked.
 */
void InputHandler::checkFile(const std::string &filename)
{
    std::map<std::string, std::string> key_command_map;
    std::map<std::string, std::string> command_key_map;

    std::ifstream file(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Не удалось открыть файл " + filename + "\n");
    }

    std::string key, command;
    while (file >> key >> command)
    {
        if (key_command_map.find(key) != key_command_map.end())
        {
            throw std::runtime_error("Ошибка: клавиша " + key + " назначена на две команды: " + key_command_map[key] + " и " + command + "\n");
        }
        if (command_key_map.find(command) != command_key_map.end())
        {
            throw std::runtime_error("Ошибка: команда " + command + " назначена на две клавиши: " + command_key_map[command] + " и " + key + "\n");
        }
        key_command_map[key] = command;
        command_key_map[command] = key;
    }

    std::string commands[] = {"up", "down", "left", "right", "start", "select", "exit", "quit", "restart", "menu", "level1", "level2", "level3", "level4"};

    for (const auto &command : commands)
    {
        if (command_key_map.find(command) == command_key_map.end())
        {
            throw std::runtime_error("Ошибка: команда " + command + " не назначена на клавишу" + "\n");
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