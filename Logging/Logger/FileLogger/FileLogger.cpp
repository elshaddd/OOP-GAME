#include "FileLogger.h"

FileLogger::FileLogger(const std::string &filename)
{
    OutputFile *file;
    try
    {
        file = new OutputFile(filename);
    }
    catch (const std::runtime_error &error)
    {
        std::cout << "Logger file error: " << error.what();
        exit(0);
    }
    this->file = file;
}

void FileLogger::onEvent(Message &event)
{
    file->getFile() << event << "/n";
}