/**
 * The above code generates and prints a maze using a depth-first search algorithm.
 *
 * @return The main function returns an integer value of 0.
 */
#include <iostream>
#include <stack>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <random>

class Cell
{
public:
    int x, y;
    bool visited;
    std::vector<Cell *> neighbours;

    Cell(int x, int y) : x(x), y(y), visited(false) {}

    void addNeighbour(Cell *neighbour)
    {
        neighbours.push_back(neighbour);
    }
    ~Cell()
    {
        neighbours.clear();
    }
};

class Maze
{
public:
    std::stack<Cell *> cellStack;
    std::vector<std::vector<Cell *>> cells;
    int width, height;

public:
    Maze(int width, int height) : width(width), height(height)
    {
        cells.resize(height, std::vector<Cell *>(width));
        for (int y = 0; y < height; y++)
        {
            for (int x = 0; x < width; x++)
            {
                cells[y][x] = new Cell(x, y);
            }
        }
    }

    void addNeighbour(Cell *c, int x, int y)
    {
        if (x > 0 && y > 0 && x < width - 1 && y < height - 1)
        {
            c->addNeighbour(cells[y][x]);
        }
    }

    void removeWall(Cell *a, Cell *b)
    {
        if (a->x - b->x == 2)
        {
            cells[a->y][a->x - 1]->visited = true;
        }
        if (a->x - b->x == -2)
        {
            cells[a->y][a->x + 1]->visited = true;
        }
        if (a->y - b->y == 2)
        {
            cells[a->y - 1][a->x]->visited = true;
        }
        if (a->y - b->y == -2)
        {
            cells[a->y + 1][a->x]->visited = true;
        }
    }

    void generateMaze(Cell *start)
    {
        start->visited = true;
        std::random_device rd;
        std::mt19937 gen(rd());
        while (!cellStack.empty())
        {
            Cell *current = cellStack.top();
            cellStack.pop();
            std::vector<Cell *> unvisitedNeighbours;
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
                std::uniform_int_distribution<> distr(0, unvisitedNeighbours.size() - 1);
                int randomIndex = distr(gen);
                removeWall(current, unvisitedNeighbours[randomIndex]);
                unvisitedNeighbours[randomIndex]->visited = true;
                cellStack.push(unvisitedNeighbours[randomIndex]);
            }
        }
    }

    void printMaze()
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width; j++)
            {
                if (cells[i][j]->visited)
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

    ~Maze()
    {
        for (auto &row : cells)
        {
            for (auto &cell : row)
            {
                delete cell;
            }
        }
    }
};

int main()
{
    // srand(time(NULL));
    int width = 7;
    int height = 5;
    Maze maze(width, height);
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            maze.addNeighbour(maze.cells[y][x], x - 2, y);
            maze.addNeighbour(maze.cells[y][x], x, y - 2);
            maze.addNeighbour(maze.cells[y][x], x + 2, y);
            maze.addNeighbour(maze.cells[y][x], x, y + 2);
        }
    }
    Cell *start = maze.cells[1][1];
    maze.cellStack.push(start);
    maze.generateMaze(start);
    maze.printMaze();
    return 0;
}
