#include "FileChecker.h"
/**
 * The function `checkFile` reads a file containing key-command mappings and checks for any errors or
 * missing mappings.
 *
 * @param filename The `filename` parameter is a string that represents the name of the file to be
 * checked.
 */
void FileChecker::checkFile(const std::string &filename)
{
    std::map<std::string, std::string> key_command_map;
    std::map<std::string, std::string> command_key_map;

    FileWrapper *fileWrapper;
    try
    {
        fileWrapper = new FileWrapper(filename);
    }
    catch (const std::runtime_error &error)
    {
        std::cout << "Config file error: " << error.what() << '\n';
        exit(0);
    }
    std::string key, command;

    while (fileWrapper->readData(key, command))
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