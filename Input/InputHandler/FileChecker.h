#ifndef FILE_CHECKER_H
#define FILE_CHECKER_H
#include <map>
#include <fstream>

#include "../../FileWrapper/FileWrapper.h"

class FileChecker
{
public:
    void checkFile(const std::string &filename);
};

#endif