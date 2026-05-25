#pragma once
#include <string>
class FileReadException : public std::runtime_error
{
public:
    FileReadException(const std::string &fileName)
        : std::runtime_error("Cannot open file: " + fileName) {}
};