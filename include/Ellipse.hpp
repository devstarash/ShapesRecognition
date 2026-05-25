#pragma once
#include <string>
#include "Shape.hpp"
class Ellipse : public Shape
{
private:
    double x, y;
    double a, b;

public:
    Ellipse(double x, double y, double a, double b)
        : x(x), y(y), a(a), b(b) {}
    double calcArea() const override;
    double calcPerimeter() const override;
    std::string getName() const override;
};