#include "../include/GridLoader.hpp"
#include "../include/ComponentFinder.hpp"
#include "../include/ShapeClassifier.hpp"
#include "../include/ResultWriter.hpp"
#include "../../include/Rectangle.hpp"
#include "../../include/Circle.hpp"
#include "../../include/Triangle.hpp"
#include "../../include/Polygon.hpp"
#include "../../include/VerticesFileReader.hpp"
#include <iostream>
#include <cmath>

int main()
{
    GridLoader loader;
    std::vector<std::vector<uint8_t>> grid = loader.load("tasks/resources/input1.dat");

    ComponentFinder finder;
    std::vector<Component> components = finder.find(grid);

    ShapeClassifier classifier;
    int rectangles = 0, circles = 0, triangles = 0, noise = 0;
    std::vector<Shape *> shapes;

    for (int i = 0; i < components.size(); i++)
    {
        ShapeType type = classifier.classify(components[i]);

        if (type == ShapeType::Skip)
            continue;

        if (type == ShapeType::Rectangle)
        {
            rectangles++;
            shapes.push_back(new Rectangle(components[i].W, components[i].H));
        }
        else if (type == ShapeType::Circle)
        {
            circles++;
            double r = (components[i].H + components[i].W) / 4.0;
            shapes.push_back(new Circle(0, 0, r));
        }
        else if (type == ShapeType::Triangle)
        {
            triangles++;
            shapes.push_back(new Triangle(
                components[i].W,
                components[i].W,
                components[i].H));
        }
        else
        {
            noise++;
        }
    }

    double totalArea = 0;
    for (int i = 0; i < shapes.size(); i++)
        totalArea += shapes[i]->calcArea();

    std::vector<Point> pts = VerticesFileReader::readFromFile(
        "tasks/resources/granitsy-uchastka2.txt");
    Polygon boundary(pts);
    double boundaryArea = boundary.calcArea();

    for (int i = 0; i < shapes.size(); i++)
        delete shapes[i];

    ResultWriter writer;
    writer.write("tasks/resources/output.txt", rectangles, circles, triangles, noise);

    std::cout << "Rectangle = " << rectangles << "\n";
    std::cout << "Circle    = " << circles << "\n";
    std::cout << "Triangle  = " << triangles << "\n";
    std::cout << "Noise     = " << noise << "\n";
    std::cout << "Total area of shapes = " << totalArea << "\n";
    std::cout << "Area of boundary     = " << boundaryArea << "\n";

    return 0;
}