#pragma once
#include "Polygon.hpp"
#include <cmath>

class Triangle : public Polygon
{
public:
    Triangle(Point a, Point b, Point c) : Polygon({a, b, c}) {}
    static std::vector<Point> fromSides(double a, double b, double c)
    {
        double x = (c * c + b * b - a * a) / (2 * c);
        double y = std::sqrt(b * b - x * x);
        return {{0, 0}, {c, 0}, {x, y}};
    }
    Triangle(double a, double b, double c)
        : Polygon(fromSides(a, b, c)) {}

    std::string getName() const override;
};