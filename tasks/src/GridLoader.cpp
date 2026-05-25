#include "GridLoader.hpp"
#include <fstream>
#include <stdexcept>

std::vector<std::vector<uint8_t>> GridLoader::load(const std::string &filename)
{
    std::ifstream fs(filename);
    if (!fs.is_open())
        throw std::runtime_error("Cannot open file: " + filename);

    std::vector<std::vector<uint8_t>> grid;
    std::string line;
    while (std::getline(fs, line))
    {
        if (line.empty())
            continue;

        if (line.back() == '\r')
            line.pop_back();

        std::vector<uint8_t> row;
        for (char c : line)
            row.push_back(c == '1' ? 1 : 0);
        grid.push_back(row);
    }
    return grid;
}