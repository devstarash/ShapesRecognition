#include "../include/Polygon.hpp"
double Polygon::calcArea() const
{
    double sum = 0;
    int n = vertices.size();
    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;
        sum += vertices[i].x * vertices[j].y;
        sum -= vertices[j].x * vertices[i].y;
    }
    return std::abs(sum) / 2.0;
}
double Polygon ::calcPerimeter() const
{
    double perimeter = 0;
    int n = vertices.size();
    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;
        perimeter += std::sqrt(((vertices[j].x - vertices[i].x) * (vertices[j].x - vertices[i].x)) +
                               ((vertices[j].y - vertices[i].y) * (vertices[j].y - vertices[i].y)));
    }
    return perimeter;
}
std::string Polygon::getName() const
{
    return "Polygon";
}