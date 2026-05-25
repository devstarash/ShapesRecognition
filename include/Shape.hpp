#pragma once
#include <string>

class Shape
{
public:
    virtual double calcArea() const = 0;
    virtual double calcPerimeter() const = 0;
    virtual std::string getName() const = 0;
    virtual ~Shape() = default;
};