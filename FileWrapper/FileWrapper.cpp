#include "FileWrapper.h"

FileWrapper::FileWrapper(const std::string &filename) : file(filename)
{
    if (!file.is_open())
        throw std::runtime_error("File open failure");
}

FileWrapper::~FileWrapper()
{
    if (file.is_open())
        file.close();
}

bool FileWrapper::readData(char &key, std::string &command)
{
    if (file >> key >> command)
        return true;
    else
        return false;
}

bool FileWrapper::readData(std::string &key, std::string &command)
{
    if (file >> key >> command)
        return true;
    else
        return false;
}

bool FileWrapper::readData(char &key)
{
    if (file >> key)
        return true;
    else
        return false;
}