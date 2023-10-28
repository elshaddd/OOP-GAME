#include "FileInputSource.h"

FileInputSource::FileInputSource(const std::string &filename) : file(filename) {}

char FileInputSource::getInput()
{
    char key;
    if (file >> key)
    {
        return key;
    }
    return '\0'; // ret 0 if EOF
}
