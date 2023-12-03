#include "InputHandler.h"

InputHandler::InputHandler(IMove *controller, IGame *game, InputSource &inputSource, MessageDispatcher *dispatcher) : controller(controller), game(game), inputSource(inputSource), dispatcher(dispatcher)
{
    loadCommandsFromFile("keys.txt");
}

void InputHandler::loadCommandsFromFile(const std::string &filename)
{
    FileChecker checker;
    try
    {
        checker.checkFile(filename);
    }
    catch (const std::runtime_error &error)
    {
        std::cout << "Invalid config error: " << error.what();
        exit(0);
    }
    FileWrapper fileWrapper(filename);
    char key;
    std::string command;
    while (fileWrapper.readData(key, command))
    {
        if (command == "up")
        {
            keyToCommandMap[key] = new MoveCommand(controller, UP);
        }
        else if (command == "down")
        {
            keyToCommandMap[key] = new MoveCommand(controller, DOWN);
        }
        else if (command == "left")
        {
            keyToCommandMap[key] = new MoveCommand(controller, LEFT);
        }
        else if (command == "right")
        {
            keyToCommandMap[key] = new MoveCommand(controller, RIGHT);
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

Command *InputHandler::handleInput()
{
    char key = inputSource.getInput();
    if (keyToCommandMap.find(key) != keyToCommandMap.end())
    {
        if (dispatcher != nullptr)
        {
            CommandExecuted event(key, keyToCommandMap[key]);
            dispatcher->dispatchEvent(event);
        }
        return keyToCommandMap[key];
    }
    if (dispatcher != nullptr)
    {
        CommandFailed event(key);
        dispatcher->dispatchEvent(event);
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