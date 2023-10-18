#include <iostream>
#include <stack>
#include <vector>
#include <stdlib.h>
#include <time.h>

struct cell
{
    int x, y;
    bool visited;
    std::vector<cell *> neighbours;
};

std::stack<cell *> cellStack;
std::vector<std::vector<cell>> maze;

void addNeighbour(cell &c, int x, int y, int width, int height)
{
    if (x > 0 && y > 0 && x < width - 1 && y < height - 1)
    {
        c.neighbours.push_back(&maze[x][y]);
    }
}

void removeWall(cell *a, cell *b)
{
    if (a->x - b->x == 2)
    {
        maze[a->x - 1][a->y].visited = true;
    }
    if (a->x - b->x == -2)
    {
        maze[a->x + 1][a->y].visited = true;
    }
    if (a->y - b->y == 2)
    {
        maze[a->x][a->y - 1].visited = true;
    }
    if (a->y - b->y == -2)
    {
        maze[a->x][a->y + 1].visited = true;
    }
}

void generateMaze(cell *start, int width, int height)
{
    start->visited = true;

    while (!cellStack.empty())
    {
        cell *current = cellStack.top();
        cellStack.pop();
        std::vector<cell *> unvisitedNeighbours;
        for (auto neighbour : current->neighbours)
        {
            if (!neighbour->visited)
            {
                unvisitedNeighbours.push_back(neighbour);
            }
        }
        if (!unvisitedNeighbours.empty())
        {
            cellStack.push(current);
            int randomIndex = rand() % unvisitedNeighbours.size();
            removeWall(current, unvisitedNeighbours[randomIndex]);
            unvisitedNeighbours[randomIndex]->visited = true;
            cellStack.push(unvisitedNeighbours[randomIndex]);
        }
    }
}

void printMaze(int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (maze[j][i].visited)
            {
                std::cout << " " << ' ';
            }
            else
            {
                std::cout << "*" << ' ';
            }
        }
        std::cout << "\n";
    }
}

int main()
{

    srand(time(NULL));
    int width = 51;
    int height = 25;
    maze.resize(width, std::vector<cell>(height));
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            maze[x][y] = {x, y, false};
            addNeighbour(maze[x][y], x - 2, y, width, height);
            addNeighbour(maze[x][y], x, y - 2, width, height);
            addNeighbour(maze[x][y], x + 2, y, width, height);
            addNeighbour(maze[x][y], x, y + 2, width, height);
        }
    }
    cell *start = &maze[1][1];
    cellStack.push(start);
    generateMaze(start, width, height);
    printMaze(width, height);
    return 0;
}