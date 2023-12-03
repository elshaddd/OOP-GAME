#ifndef FILE_LOGGER_H
#define FILE_LOGGER_H

#include "../Observer.h"
#include "../../../FileWrapper/OutputFile.h"
#include <string>

class FileLogger : public Observer
{
private:
    OutputFile *file;
public:
    FileLogger(const std::string &filename);
    void onEvent(Message &event) override;
};

#endif