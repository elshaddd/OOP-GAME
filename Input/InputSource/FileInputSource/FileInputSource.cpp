#include "FileInputSource.h"

FileInputSource::FileInputSource(const std::string &filename)
{
    FileWrapper *file;
    try
    {
        file = new FileWrapper(filename);
    }
    catch (const std::runtime_error &error)
    {
        std::cout << "Input file error: " << error.what();
        exit(0);
    }
    this->file = file;
}

/**
 * The function `getInput` reads a character from a file and returns it, or returns '\0' if the end of
 * the file has been reached.
 *
 * @return a character value. If there is a character available to read from the file, it will return
 * that character. If the end of the file (EOF) has been reached, it will exit the program.
 */
char FileInputSource::getInput()
{
    char key;
    if (file->readData(key))
    {
        return key;
    }
    exit(0);
}