#pragma once
#include "ComponentFinder.hpp"

enum class ShapeType
{
    Rectangle,
    Circle,
    Triangle,
    Noise,
    Skip
};

class ShapeClassifier
{
private:
    bool isRectangle(const Component &comp);
    bool isCircle(const Component &comp);
    bool isTriangle(const Component &comp);
    bool isSmall(const Component &comp);
    int countVertices(const Component &comp);
    bool similar(std::pair<int, int> a, std::pair<int, int> b);
    bool addIfUnique(std::vector<std::pair<int, int>> &vertices, std::pair<int, int> p);

public:
    ShapeType classify(const Component &comp);
};