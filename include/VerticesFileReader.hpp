#pragma once
#include "Polygon.hpp"
#include <string>
#include <fstream>
#include "../Exceptions/FileReadException.hpp"

class VerticesFileReader
{
public:
    static std::vector<Point> readFromFile(const std::string& filename);
};