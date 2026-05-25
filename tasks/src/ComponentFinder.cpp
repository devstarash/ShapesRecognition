#include "../include/ComponentFinder.hpp"

std::vector<std::pair<int, int>> ComponentFinder::getNeighbors(int r, int c)
{
    return {
        {r-1, c},    
        {r+1, c},    
        {r, c-1},   
        {r, c+1},    
        {r-1, c-1}, 
        {r-1, c+1},
        {r+1, c-1},
        {r+1, c+1}
    };
}

void ComponentFinder::calcBounds(Component &comp)
{
    comp.minR = comp.pixels[0].first;
    comp.maxR = comp.pixels[0].first;
    comp.minC = comp.pixels[0].second;
    comp.maxC = comp.pixels[0].second;

    for (int i = 0; i < comp.pixels.size(); i++)
    {
        int pr = comp.pixels[i].first;
        int pc = comp.pixels[i].second;

        if (pr < comp.minR)
            comp.minR = pr;
        if (pr > comp.maxR)
            comp.maxR = pr;
        if (pc < comp.minC)
            comp.minC = pc;
        if (pc > comp.maxC)
            comp.maxC = pc;
    }

    comp.H = comp.maxR - comp.minR + 1;
    comp.W = comp.maxC - comp.minC + 1;
}

Component ComponentFinder::bfs(int r, int c,
                               const std::vector<std::vector<uint8_t>> &grid,
                               std::vector<std::vector<bool>> &visited)
{
    int rows = grid.size();
    int cols = grid[0].size();

    Component comp;
    std::queue<std::pair<int, int>> queue;
    queue.push({r, c});
    visited[r][c] = true;

    while (!queue.empty())
    {
        std::pair<int, int> current = queue.front();
        queue.pop();
        int cr = current.first;
        int cc = current.second;
        comp.pixels.push_back({cr, cc});

        std::vector<std::pair<int, int>> neighbors = getNeighbors(cr, cc);
        for (int d = 0; d < neighbors.size(); d++)
        {
            int nr = neighbors[d].first;
            int nc = neighbors[d].second;
            if (nr >= 0 && nr < rows &&
                nc >= 0 && nc < cols &&
                grid[nr][nc] == 1 &&
                !visited[nr][nc])
            {
                visited[nr][nc] = true;
                queue.push({nr, nc});
            }
        }
    }
    calcBounds(comp);
    return comp;
}

std::vector<Component> ComponentFinder::find(
    const std::vector<std::vector<uint8_t>> &grid)
{
    int rows = grid.size();
    int cols = grid[0].size();
    std::vector<std::vector<bool>> visited(rows, std::vector<bool>(cols, false));
    std::vector<Component> components;

    for (int r = 0; r < rows; r++)
        for (int c = 0; c < cols; c++)
            if (grid[r][c] == 1 && !visited[r][c])
                components.push_back(bfs(r, c, grid, visited));

    return components;
}