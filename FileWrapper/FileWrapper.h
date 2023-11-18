#ifndef FILE_WRAPPER_H
#include "iostream"
#include "fstream"
#include "string"

class FileWrapper
{
    std::ifstream file;

public:
    FileWrapper(const std::string &filename);

    ~FileWrapper();

    bool readData(char &key, std::string &command);

    bool readData(std::string &key, std::string &command);
};

#endif