#pragma once
#include <vector>
#include <queue>
struct Component
{
    std::vector<std::pair<int, int>> pixels;
    int minR, maxR;
    int minC, maxC;
    int H, W;
};

class ComponentFinder
{
private:
    std::vector<std::pair<int, int>> getNeighbors(int r, int c);
    Component bfs(int r, int c,
                  const std::vector<std::vector<uint8_t>> &grid,
                  std::vector<std::vector<bool>> &visited);

    void calcBounds(Component &comp);

public:
    std::vector<Component> find(
        const std::vector<std::vector<uint8_t>> &grid);
};