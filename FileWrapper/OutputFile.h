#ifndef OUTPUT_FILE_WRAPPER_H
#define OUTPUT_FILE_WRAPPER_H
#include "iostream"
#include "fstream"
#include "string"

class OutputFile
{
private:
    std::ofstream file;

public:
    OutputFile(const std::string &filename);
    
    ~OutputFile();
    
    std::ofstream &getFile();
};

#endif