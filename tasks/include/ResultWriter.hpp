#pragma once
#include <string>
#include <map>
#include "ShapeClassifier.hpp"

class ResultWriter
{
public:
    void write(const std::string &filename,
               int rectangles,
               int circles,
               int triangles,
               int noise);
};