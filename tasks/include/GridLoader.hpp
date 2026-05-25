#pragma once
#include <vector>
#include <string>

class GridLoader
{
public:
    static std::vector<std::vector<uint8_t>> load(const std::string &filename);
};