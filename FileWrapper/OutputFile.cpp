#include "OutputFile.h"

OutputFile::OutputFile(const std::string &filename)
{
    file.open(filename);
    if (!file.is_open())
    {
        throw std::runtime_error("Failed to open file logger");
    }
}

OutputFile::~OutputFile()
{
    if (file.is_open())
    {
        file.close();
    }
}

std::ofstream &OutputFile::getFile()
{
    return file;
}

void OutputFile::writeData(std::string &data)
{
    file << data;
}