#include "../include/Ellipse.hpp"
#include "../include/Ellipse.hpp"
#include <cmath>

double Ellipse::calcArea() const
{
    return M_PI * a * b;
}

double Ellipse::calcPerimeter() const
{
    return M_PI * (3 * (a + b) - std::sqrt((3 * a + b) * (a + 3 * b)));
}

std::string Ellipse::getName() const
{
    return "Ellipse";
}