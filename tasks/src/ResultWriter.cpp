#include "../include/ResultWriter.hpp"
#include <fstream>
#include <stdexcept>

void ResultWriter::write(const std::string &filename,
                         int rectangles,
                         int circles,
                         int triangles,
                         int noise)
{
    std::ofstream fs(filename);
    if (!fs.is_open())
        throw std::runtime_error("Cannot open file: " + filename);

    fs << "Rectangle = " << rectangles << "\n";
    fs << "Circle = "    << circles    << "\n";
    fs << "Triangle = "  << triangles  << "\n";
    fs << "Noise = "     << noise      << "\n";
}