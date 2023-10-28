#ifndef FILE_INPUT_SOURCE_H
#define FILE_INPUT_SOURCE_H
#include "../InputSource.h"
#include <fstream>

class FileInputSource : public InputSource
{
private:
    std::ifstream file;

public:
    FileInputSource(const std::string &filename) : file(filename) {}
    
    char getInput() override;
};

#endif