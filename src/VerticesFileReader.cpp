#include "../include/VerticesFileReader.hpp"
std::vector<Point> VerticesFileReader::readFromFile(const std::string &fileName)
{
    std::ifstream fs(fileName);
    if (!fs.is_open())
    {
        throw FileReadException(fileName);
    }
    std::vector<Point> vertices;
    int n;
    fs >> n;
    for (int i = 0; i < n; i++)
    {
        Point p;
        fs >> p.x >> p.y;
        vertices.push_back(p);
    }
    return vertices;
}
