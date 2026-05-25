#include "../include/ShapeClassifier.hpp"
#include <cmath>

bool ShapeClassifier::similar(std::pair<int, int> a, std::pair<int, int> b)
{
    return std::abs(a.first - b.first) <= 3 &&
           std::abs(a.second - b.second) <= 3;
}

bool ShapeClassifier::addIfUnique(std::vector<std::pair<int, int>> &vertices,
                                  std::pair<int, int> p)
{
    for (int i = 0; i < vertices.size(); i++)
        if (similar(vertices[i], p))
            return false;
    vertices.push_back(p);
    return true;
}

int ShapeClassifier::countVertices(const Component &comp)
{
    std::pair<int, int> top = comp.pixels[0];
    std::pair<int, int> bottom = comp.pixels[0];
    std::pair<int, int> left = comp.pixels[0];
    std::pair<int, int> right = comp.pixels[0];

    for (int i = 1; i < comp.pixels.size(); i++)
    {
        int r = comp.pixels[i].first;
        int c = comp.pixels[i].second;
        if (r < top.first)
            top = comp.pixels[i];
        if (r > bottom.first)
            bottom = comp.pixels[i];
        if (c < left.second)
            left = comp.pixels[i];
        if (c > right.second)
            right = comp.pixels[i];
    }

    std::vector<std::pair<int, int>> vertices;
    vertices.push_back(top);
    addIfUnique(vertices, bottom);
    addIfUnique(vertices, left);
    addIfUnique(vertices, right);

    return vertices.size();
}

bool ShapeClassifier::isSmall(const Component &comp)
{
    return comp.H < 5 || comp.W < 5;
}

bool ShapeClassifier::isRectangle(const Component &comp)
{
    std::vector<int> leftEdge(comp.H, INT_MAX);
    std::vector<int> rightEdge(comp.H, INT_MIN);
    for (int i = 0; i < comp.pixels.size(); i++)
    {
        int pr = comp.pixels[i].first - comp.minR;
        int pc = comp.pixels[i].second;
        if (pc < leftEdge[pr])
            leftEdge[pr] = pc;
        if (pc > rightEdge[pr])
            rightEdge[pr] = pc;
    }
    for (int i = 1; i < comp.H; i++)
    {
        if (leftEdge[i] != leftEdge[0])
            return false;
        if (rightEdge[i] != rightEdge[0])
            return false;
    }
    return true;
}

bool ShapeClassifier::isCircle(const Component &comp)
{
    double aspect = (double)comp.H / comp.W;
    if (aspect < 0.75 || aspect > 1.35)
        return false;
    double fillRatio = (double)comp.pixels.size() / (comp.H * comp.W);
    double piRatio = M_PI / 4.0;
    return std::abs(fillRatio - piRatio) < 0.15;
}

bool ShapeClassifier::isTriangle(const Component &comp)
{
    int v = countVertices(comp);
    if (v != 3)
        return false;
    double fillRatio = (double)comp.pixels.size() / (comp.H * comp.W);
    if (fillRatio < 0.3)
        return false;
    return true;
}

ShapeType ShapeClassifier::classify(const Component &comp)
{
    if (isSmall(comp))
        return ShapeType::Skip;
    if (isRectangle(comp))
        return ShapeType::Rectangle;
    if (isCircle(comp))
        return ShapeType::Circle;
    if (isTriangle(comp))
        return ShapeType::Triangle;
    return ShapeType::Noise;
}