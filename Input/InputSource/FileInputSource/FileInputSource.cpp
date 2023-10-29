#include "FileInputSource.h"

FileInputSource::FileInputSource(const std::string &filename) : file(filename) {}

/**
 * The function `getInput` reads a character from a file and returns it, or returns '\0' if the end of
 * the file has been reached.
 * 
 * @return a character value. If there is a character available to read from the file, it will return
 * that character. If the end of the file (EOF) has been reached, it will return the null character
 * '\0'.
 */
char FileInputSource::getInput()
{
    char key;
    if (file >> key)
    {
        return key;
    }
    return '\0'; // ret 0 if EOF
}
