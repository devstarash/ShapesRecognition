#pragma once
#include "Ellipse.hpp"

class Circle : public Ellipse
{
public:
    Circle(double x, double y, double radius)
        : Ellipse(x, y, radius, radius) {}  

    std::string getName() const override;
};