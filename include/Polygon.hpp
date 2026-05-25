#pragma once
#include <vector>
#include "Shape.hpp"
#include <cmath>
struct Point
{
    double x, y;
};
class Polygon : public Shape
{
protected:
    std::vector<Point> vertices;

public:
    Polygon(const std::vector<Point> &vertices) : vertices(vertices) {}
    double calcArea() const override;
    double calcPerimeter() const override;
    std::string getName() const override;
};

