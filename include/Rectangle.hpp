#pragma once
#include "Polygon.hpp"

class Rectangle : public Polygon
{
public:
    Rectangle(double width, double height)
        : Polygon({{0, 0}, {width, 0}, {width, height}, {0, height}}) {}
    Rectangle(Point a, Point b, Point c, Point d)
        : Polygon({a, b, c, d}) {}

    std::string getName() const override;
};