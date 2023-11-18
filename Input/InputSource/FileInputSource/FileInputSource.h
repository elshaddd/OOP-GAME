#ifndef FILE_INPUT_SOURCE_H
#define FILE_INPUT_SOURCE_H
#include "../InputSource.h"
#include "../../../FileWrapper/FileWrapper.h"

class FileInputSource : public InputSource
{
private:
    FileWrapper file;

public:
    FileInputSource(const std::string &filename);
    
    char getInput() override;
};

#endif